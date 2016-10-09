#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1003


char s[MAX][MAX];
int a[MAX][MAX];

struct gao
{
	int x,y;
}d[MAX*MAX],dd[MAX*MAX],z[4]={0,1,1,0,0,-1,-1,0};

struct poi
{
	int x1,y1,x2,y2;
}c[MAX*MAX];

int n,m,t,n1,n2;

void bfs(int ii,int jj)
{
	int i,xx,yy,j;
	n1=1;
	d[0].x=ii;
	d[0].y=jj;
	a[ii][jj]=t;
	while(n1)
	{
		n2=0;
		for(i=0;i<n1;i++)
		{
			for(j=0;j<4;j++)
			{
				xx=d[i].x+z[j].x;
				yy=d[i].y+z[j].y;
				if(xx<=0||yy<=0||xx>n||yy>m)
					continue;
				if(s[xx][yy]!='#')
					continue;
				if(a[xx][yy])
					continue;
				if(xx<c[t].x1)
					c[t].x1=xx;
				if(xx>c[t].x2)
					c[t].x2=xx;
				if(yy<c[t].y1)
					c[t].y1=yy;
				if(yy>c[t].y2)
					c[t].y2=yy;
				a[xx][yy]=t;
				dd[n2].x=xx;
				dd[n2].y=yy;
				n2++;
			}
		}
		n1=n2;
		for(i=0;i<n2;i++)
		{
			d[i].x=dd[i].x;
			d[i].y=dd[i].y;
		}
	}
}

bool judge()
{
	int i,j,k;
	for(i=1;i<t;i++)
	{
		for(j=c[i].x1;j<=c[i].x2;j++)
			for(k=c[i].y1;k<=c[i].y2;k++)
				if(a[j][k]!=i)
					return false;
		for(j=c[i].x1-1;j<=c[i].x2+1;j++)
			if(a[j][c[i].y1-1]||a[j][c[i].y2+1])
				return false;
		for(k=c[i].y1-1;k<=c[i].y2+1;k++)
			if(a[c[i].x1-1][k]||a[c[i].x2+1][k])
				return false;
	}
	return true;
}


int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d%d",&n,&m),n||m)
	{
		t=1;
		for(i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if(!a[i][j]&&s[i][j]=='#')
				{
					c[t].x1=c[t].x2=i;
					c[t].y1=c[t].y2=j;
					bfs(i,j);
					t++;
				}
			}
		if(judge())
			printf("There are %d ships.\n",t-1);
		else
			printf("Bad placement.\n");
	}			
	return 0;
}

