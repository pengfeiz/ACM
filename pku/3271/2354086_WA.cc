#include <iostream>
using namespace std;

#define MAX 31


struct gao
{
	int x,y;
}a[MAX*MAX];

gao z[8]={1,2,2,1,1,-2,-2,1,-1,2,2,-1,-1,-2,-2,-1};

int s[MAX][MAX];
int c[MAX][MAX];
int b[MAX][MAX];
int n,m,x1,y1,x2,y2,t;

void init()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&s[i][j]);
}


void ready()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(s[i][j]==3)
			{
				x1=i;
				y1=j;
			}
			else if(s[i][j]==4)
			{
				s[i][j]=0;
				x2=i;
				y2=j;
			}
		}
}


void helpbfs(int xx,int yy,int nd,gao d[],bool e[MAX][MAX])
{
	int j,x,y;
	for(j=0;j<8;j++)
	{
		x=xx+z[j].x;
		y=yy+z[j].y;
		if(x<0||x>=n||y<0||y>=m)
			continue;
		if(s[x][y]==2)
			continue;
		if(b[x][y]<=t)
			continue;
		if(s[x][y]==1&&!e[x][y])
		{
			e[x][y]=true;
			helpbfs(x,y,nd,d,e);
		}
		else if(s[x][y]==0)
		{
			d[nd].x=x;
			d[nd++].y=y;
			b[x][y]=t+1;
			e[x][y]=true;
		}		
		if(x==x2&&y==y2)
		{
			c[x][y]=1;
			b[x][y]=t;
		}
	}
}
		

void bfs(int na,gao a[])
{
	int i,j,nd=0,x,y;
	gao d[MAX*MAX];
	bool e[MAX][MAX]={0};
	for(i=0;i<na;i++)
		for(j=0;j<8;j++)
		{
			x=a[i].x+z[j].x;
			y=a[i].y+z[j].y;
			if(x<0||x>=n||y<0||y>=m)
				continue;
			if(s[x][y]==2||e[x][y])
				continue;
			if(b[x][y]<=t)
				continue;
			if(s[x][y]==1)
			{
				e[x][y]=true;
				helpbfs(x,y,nd,d,e);
			}
			else if(s[x][y]==0)
			{
				d[nd].x=x;
				d[nd++].y=y;
				b[x][y]=t+1;
				e[x][y]=true;
			}
			if(x==x2&&y==y2)
			{
				c[x][y]=1;
				b[x][y]=t;
			}
		}
	if(b[x2][y2]==2139062143)
	{
		t++;
		bfs(nd,d);
	}
	for(i=0;i<na;i++)
		for(j=0;j<8;j++)
		{
			x=a[i].x+z[j].x;
			y=a[i].y+z[j].y;
			if(x<0||x>=n||y<0||y>=m)
				continue;
			if(e[x][y])
				c[a[i].x][a[i].y]+=c[x][y];
		}
}


void solve()
{	
	memset(c,0,sizeof(c));
	memset(b,127,sizeof(b));
	a[0].x=x1;
	a[0].y=y1;
	t=0;
	b[x1][y1]=t;
	bfs(1,a);
	printf("%d\n%d\n",b[x2][y2],c[x1][y1]);
}


int main()
{
//	freopen("in.txt","r",stdin);
	init();
	ready();
	solve();
	return 0;
}