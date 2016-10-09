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

char s[MAX][MAX];
char w[MAX];
int n,m,l,ll,xx,yy;

bool find()
{
	int i=w[l]-'A';
	if(q->a[i]==NULL)
		return false;
	if(l==ll-1)
	{
		xx=q->x;
		yy=q->y;
		return true;
	}
	q=q->a[i];
	l++;
	return find();
}

void build(int he,int ha,int x)
{
	if(l==ll)
		return;
	int i=w[l]-'A',j;
	if(q->a[i]==NULL)
	{
		q->a[i]=(struct gao *)malloc(sizeof(struct gao));
		if(l==l-1)
		{
			q->x=he;
			q->y=ha;
			q->c=x+'A';
			return;
		}
		q=q->a[i];
		for(j=0;j<26;j++)
			q->a[j]=NULL;
	}
	else
	{		
		if(l==l-1)
		{
			q->x=he;
			q->y=ha;
			q->c=x+'A';
			return;
		}
		q=q->a[i];
	}
	q->x=he;
	q->y=ha;
	q->c=x+'A';
	l++;
	build(he,ha,x);
}

int find2()
{
	int i,j,k,x,y;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(s[i][j]==w[0])
			{
				for(k=0;k<8;k++)
				{
					x=i;
					y=j;
					l=0;
					while(s[x][y]==w[l]&&l<ll)
					{
						x+=z[k].x;
						y+=z[k].y;
						l++;
						if(s[x][y]!=w[l])
							break;
					}
					if(l==ll)
					{
						xx=i;
						yy=j;
						return k;
					}
				}
			}
		}
	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,t;
	scanf("%d%d%d",&n,&m,&t);
	memset(s,0,sizeof(s));
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	p=(struct gao *)malloc(sizeof(struct gao));
	for(i=0;i<26;i++)
		p->a[i]=NULL;
	for(i=0;i<26;i++)
		p->a[i]=NULL;
	for(i=0;i<t;i++)
	{
		scanf("%s",w);
		ll=strlen(w);
		q=p;
		l=0;
		if(find())
			printf("%d %d %c\n",xx-1,yy-1,q->c);
		else
		{
			j=find2();
			l=0;
			build(xx,yy,j);
			printf("%d %d %c\n",xx-1,yy-1,q->c);
		}
	}
	return 0;
}


		



