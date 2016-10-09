#include <iostream>
using namespace std;


#define MAX 1002
#define m2 1000
#define m1 1


bool a[MAX][MAX],judge;
struct gao
{
	int x,y;
}b[MAX*MAX],c[MAX*MAX];

int minn(int a,int b)
{return a<b?a:b;}
int maxx(int a,int b)
{return a>b?a:b;}
int ll(int x)
{return x*x;}


void bfs(int x,int y)
{
	int i,q,p;
	q=1;
	b[q].x=x;
	b[q].y=y;
	a[b[1].x][b[1].y]=true;
	while(q)
	{
		p=0;
		for(i=1;i<=q;i++)
		{
			if(judge&&b[i].x==0||b[i].y==0||b[i].y==m2+1||b[i].x==m2+1)
				judge=false;
			if(b[i].x>=m1&&!a[b[i].x-1][b[i].y])
			{
				a[b[i].x-1][b[i].y]=true;
				p++;
				c[p].x=b[i].x-1;
				c[p].y=b[i].y;
			}
			if(b[i].x<=m2&&!a[b[i].x+1][b[i].y])
			{
				a[b[i].x+1][b[i].y]=true;
				p++;
				c[p].x=b[i].x+1;
				c[p].y=b[i].y;
			}
			if(b[i].y>=m1&&!a[b[i].x][b[i].y-1])
			{
				a[b[i].x][b[i].y-1]=true;
				p++;
				c[p].x=b[i].x;
				c[p].y=b[i].y-1;
			}
			if(b[i].y<=m2&&!a[b[i].x][b[i].y+1])
			{
				a[b[i].x][b[i].y+1]=true;
				p++;
				c[p].x=b[i].x;
				c[p].y=b[i].y+1;
			}
		}
		q=p;
		for(i=1;i<=q;i++)
		{
			b[i].x=c[i].x;
			b[i].y=c[i].y;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int p,i,i1,i2,j,j1,j2,n,x,y,r,s,t;
	scanf("%d",&p);
	while(p--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d%d",&x,&y,&r);
			i1=maxx(m1,x-r);
			i2=minn(m2,x+r);
			j1=maxx(m1,y-r);
			j2=minn(m2,y+r);
			r*=r;
			for(i=i1;i<=i2;i++)
				for(j=j1;j<=j2;j++)
				{
					s=ll(i-x)+ll(j-y);
					if(s<=r)
						a[i][j]=true;
				}
		}
		t=0;
		for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
			{
				if(a[i][j])
					continue;
				judge=true;
				bfs(i,j);
				if(judge)
					t++;	
			}
		printf("%d\n",t);
	}
	return 0;
}