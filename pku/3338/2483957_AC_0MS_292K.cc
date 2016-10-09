#include <iostream>
#include <algorithm>
using namespace std;

__int64 a[51];

struct gao
{
	__int64 x,y;
}d[2501],dd[2501],z[4]={1,0,0,1,-1,0,0,-1};

__int64 b[21][21];
bool c[21][21];
__int64 n,m,n1,n2;

void bfs(__int64 x,__int64 y)
{
	__int64 i,xx,yy,j;
	n1=1;
	c[x][y]=true;
	d[0].x=x;
	d[0].y=y;
	while(n1)
	{
		n2=0;
		for(i=0;i<n1;i++)
		{
			for(j=0;j<4;j++)
			{
				xx=d[i].x+z[j].x;
				yy=d[i].y+z[j].y;
				if(xx<0||yy<0||xx>=n||yy>=m)
					continue;
				if(c[xx][yy]==true)
					continue;
				if(b[xx][yy]!=b[d[i].x][d[i].y])
					continue;
				c[xx][yy]=true;
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
int main()
{
	__int64 i,j,t,x1,y1,x2,y2,k;
	for(i=0;i<51;i++)
		a[i]=1<<i;
	while(scanf("%I64d%I64d",&n,&m),n||m)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%I64d",&t);
		for(k=0;k<t;k++)
		{
			scanf("%I64d%I64d%I64d%I64d",&y1,&x1,&y2,&x2);
			if(x1>x2)
				swap(x1,x2);
			if(y1>y2)
				swap(y1,y2);
			for(i=x1;i<x2;i++)
				for(j=y1;j<y2;j++)
					b[i][j]+=a[k];
		}
		t=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(c[i][j])
					continue;
				else
				{
					t++;
					bfs(i,j);
				}
			}
		printf("%I64d\n",t);
	}
	return 0;
}

