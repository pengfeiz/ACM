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
bool bb[MAX][MAX];
int n,m,l,xx,yy,jj;


bool com(gao2 a,gao2 b)
{return a.l>b.l;}
bool com2(gao2 a,gao2 b)
{return a.n<b.n;}

bool find()
{
	int i=w[jj].s[l]-'A';
	if(q->a[i]==NULL)
		return false;
	if(l==w[jj].l-1)
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
			if(s[i][j]==w[jj].s[0]&&!bb[i][j])
			{
				for(k=0;k<8;k++)
				{
					x=i+(w[jj].l-1)*z[k].x;
					y=j+(w[jj].l-1)*z[k].y;
					if(x<1||y<1||x>n||y>m)
						continue;
					x=i;
					y=j;
					l=0;
					while(s[x][y]==w[jj].s[l]&&l<w[jj].l)
					{
						x+=z[k].x;
						y+=z[k].y;
						l++;
					}
					if(l==w[jj].l)
					{
						bb[i][j]=true;
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
//	freopen("in6","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,j,t;
	scanf("%d%d%d",&n,&m,&t);
	memset(s,0,sizeof(s));
	memset(bb,0,sizeof(bb));
	for(i=1;i<=n;i++)
//		for(j=1;j<=m;j++)
//			s[i][j]='A';
		scanf("%s",s[i]+1);
	p=(struct gao *)malloc(sizeof(struct gao));
	for(i=0;i<26;i++)
		p->a[i]=NULL;
	for(i=0;i<t;i++)
	{
		scanf("%s",w[i].s);
		w[i].l=strlen(w[i].s);
		w[i].n=i;
	}
	sort(w,w+t,com);
	for(jj=0;jj<t;jj++)
	{
/*		for(j=0;j<1000;j++)
			w[j]='A';
		w[j]='\0';*/
		q=p;
		l=0;
		if(find())
		{
			w[jj].c=q->c;
			w[jj].x=xx-1;
			w[jj].y=yy-1;
		}
		else
		{
			j=find2();
			l=0;
			build(xx,yy,j);
			w[jj].c=j+'A';
			w[jj].x=xx-1;
			w[jj].y=yy-1;
		}
	}
	sort(w,w+t,com2);
	for(i=0;i<t;i++)
		printf("%d %d %c\n",w[i].x,w[i].y,w[i].c);
	return 0;
}


		



