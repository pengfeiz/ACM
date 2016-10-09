#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define MAX 1002

struct gao
{
	int x,y;
	char c;
	struct gao *a[26];
}*p,*q;

struct poi
{
	int x,y;
}z[8]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};


struct gao2
{
	int n,x,y,l;
	char c;
	char s[MAX];
}w[MAX];

char s[MAX][MAX];
int n,m,l,xx,yy,jj;


void find()
{
	int i=w[jj].s[l]-'A';
	if(l==w[jj].l)
		return;
	q=q->a[i];
	l++;
	find();
}

void build()
{
	if(l==w[jj].l)
		return;
	int i=w[jj].s[l]-'A',j;
	if(q->a[i]==NULL)
	{
		q->a[i]=(struct gao *)malloc(sizeof(struct gao));
		q=q->a[i];
		for(j=0;j<26;j++)
			q->a[j]=NULL;
	}
	else
		q=q->a[i];
	l++;
	build();
}

int solve()
{
	int i,j,k,x,y;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			for(k=0;k<8;k++)
			{
				x=i;
				y=j;
				q=p;
				while(s[x][y]>='A'&&s[x][y]<='Z'&&q->a[s[x][y]-'A']!=NULL)
				{
					q=q->a[s[x][y]-'A'];
					q->x=i;
					q->y=j;
					q->c=k+'A';
					x+=z[k].x;
					y+=z[k].y;
				}
			}
	return 0;
}

int main()
{
//	freopen("in1","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,t;
	scanf("%d%d%d",&n,&m,&t);
	memset(s,0,sizeof(s));
	for(i=1;i<=n;i++)
//		for(j=1;j<=m;j++)
//			s[i][j]='A';
		scanf("%s",s[i]+1);
	p=(struct gao *)malloc(sizeof(struct gao));
	for(i=0;i<26;i++)
		p->a[i]=NULL;
	for(jj=0;jj<t;jj++)
	{
		scanf("%s",w[jj].s);
		w[jj].l=strlen(w[jj].s);
		l=0;
		q=p;
		build();
	}
	solve();
	for(jj=0;jj<t;jj++)
	{
		l=0;
		q=p;
		find();
		printf("%d %d %c\n",q->x-1,q->y-1,q->c);
	}
	return 0;
}
