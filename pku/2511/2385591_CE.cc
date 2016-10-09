#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char origName[35];
    char name[35];
    int len;
    int eval;
}Title;

typedef struct {
    int val;
    int px, py;
}Table;

typedef struct {
    int adj[2501];
    int num;
}Adjlist;

int N;
Title books[2550];
Table table[11][2500];
Adjlist alist[2501];

int compareBooks( const void* A, const void* B )
{
    Title* a = (Title*)A;
    Title* b = (Title*)B;

    return strcmp( a->name, b->name );
}

int canBeNext( int b1, int b2 )
{
    int i, len;
    len = books[b1].len < books[b2].len ? books[b1].len : books[b2].len;

    for ( i = 0; i < len; i++ )
    {
	if ( books[b1].name[i] == books[b2].name[i] ) return 0;
    }
    return 1;
}

int main()
{
    int i, len, j, best, bestR, bestC, newval, k;
    int titles[11];
    int numTitles;
    int curX, curY, nextX, nextY;
    int max, maxR, maxC;
    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
    {
	scanf( "%d ", &books[i].eval );
	books[i].len = 0;
	fgets( books[i].origName, 40, stdin );
	len = strlen( books[i].origName );
	books[i].origName[--len] = '\0';
	books[i].name[books[i].len]='\0';
    }
    qsort(books,N,sizeof( Title ),(void*)compareBooks );
    for(i=1;i<N;i++ )
    {
	alist[i].num = 0;
	for(j=0;j<i;j++ )
	    if(canBeNext(i,j))
	        alist[i].adj[alist[i].num++]=j;

    }
    
    max = -1;
    maxR = 0;
    maxC = 0;
    for ( i = 0; i < N; i++ )
    {
	table[0][i].val = books[i].eval;
	table[0][i].px = -1;
	table[0][i].py = -1;
	if ( table[0][i].val >= max )
	{
	    max = table[0][i].val;
	    maxR = 0;
	    maxC = i;
	}
    }
    for ( i = 1; i < 10; i++ )
    {
	for ( j = i; j < N; j++ )
	{
	    best = table[i-1][j].val;
	    bestR = i-1;
	    bestC = j;
	    for ( k = 0; k < alist[j].num; k++ )
	    {
		newval = table[i-1][alist[j].adj[k]].val + books[j].eval;
		if ( newval > best )
		{
		    best = newval;
		    bestR = i-1;
		    bestC = alist[j].adj[k];
		}
	    }
	    if ( best >= max )
	    {
		max = best;
		maxR = i;
		maxC = j;
	    }
	    table[i][j].val = best;
	    table[i][j].px = bestR;
	    table[i][j].py = bestC;
	}
    }
    curX = maxR;
    curY = maxC;
    numTitles = 0;
    while( curX >= 0 )
    {
	nextX = table[curX][curY].px;
	nextY = table[curX][curY].py;
	if ( nextX != curX )
	{
	    if ( nextY != curY || nextX == -1 )
	    {
		titles[numTitles++] = curY;
	    }
	}
	curX = nextX;
	curY = nextY;
    }

    printf( "%d\n%d\n", numTitles, table[maxR][maxC].val );
    for ( i = numTitles-1; i >= 0; i-- )
	printf( "%s\n", books[titles[i]].origName );
    return 0;
}