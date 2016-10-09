#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 300

char	s[MAX][33];
char	c[30];
int		n,m,t,a[MAX],b[MAX],d[MAX][MAX];

int max(int a,int b)
{return a>b?a:b;}

void outt(int x,int y)
{
	if(x<1||y<1)
		return;
	if(d[x-1][y]==d[x][y])
		outt(x-1,y);
	else if(d[x][y-1]==d[x][y])
		outt(x,y-1);
	else
	{
		outt(x-1,y-1);
		printf("%s",s[a[x]]);
		if(x!=n&&y!=m)
			printf(" ");
	}
}


void dosth()
{
	int i,j,t;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
				t=d[i-1][j-1]+1;
			else
				t=0;
			t=max(t,d[i-1][j]);
			t=max(t,d[i][j-1]);
			d[i][j]=t;
		}
	outt(n,m);
	printf("\n");
}

int main()
{
	int i;
	while(scanf("%s",c)!=EOF)
	{
		memset(d,0,sizeof(d));
		strcpy(s[0],c);
		a[1]=0;
		n=2;
		t=1;
		while(scanf("%s",c))
		{
			if(strcmp(c,"#")==0)
				break;
			for(i=0;i<t;i++)
				if(strcmp(s[i],c)==0)
					break;
			if(i==t)
			{
				strcpy(s[t],c);
				t++;
			}
			a[n++]=i;
		}
		n--;
		m=1;
		while(scanf("%s",c))
		{
			if(strcmp(c,"#")==0)
				break;
			for(i=0;i<t;i++)
				if(strcmp(s[i],c)==0)
					break;
			if(i==t)
			{
				strcpy(s[t],c);
				t++;
			}
			b[m++]=i;
		}
		m--;
		dosth();
	}
	return 0;
}
