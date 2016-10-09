#include <iostream>
#include <vector>
using namespace std;

#define MAX 200
int n,m,x,y;

struct gao
{
	int x,y;
}z[4]={0,1,1,0,0,-1,-1,0},b[MAX*MAX],bb[MAX*MAX];

int a[MAX][MAX][4],n1,n2;
int d[MAX][MAX];
int c[MAX][MAX];

void bfs()
{
	int t=0,i,j,xx,yy;
	n1=1;
	b[0].x=x;
	b[0].y=y;
	d[x][y]=0;
	c[x][y]=t;
	while(n1)
	{
		t++;
		n2=0;
		for(i=0;i<n1;i++)
		{
			for(j=0;j<4;j++)
			{
				xx=b[i].x+z[j].x;
				yy=b[i].y+z[j].y;
				if(xx<0||yy<0||xx>199||yy>199)
					continue;
				if(d[b[i].x][b[i].y]+a[b[i].x][b[i].y][j]<d[xx][yy])
				{
					d[xx][yy]=d[b[i].x][b[i].y]+a[b[i].x][b[i].y][j];
					if(c[xx][yy]!=t)
					{
						bb[n2].x=xx;
						bb[n2].y=yy;
						n2++;
						c[xx][yy]=t;
					}
				}
			}
		}
		n1=n2;
		for(i=0;i<n1;i++)
		{
			b[i].x=bb[i].x;
			b[i].y=bb[i].y;
		}
	}
}						


int main()
{
//	freopen("in.txt","r",stdin);
	int i,l,b,j;
	double xx,yy;
	while(scanf("%d%d",&n,&m),(n+1)||(m+1))
	{
		memset(a,0,sizeof(a));
		for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
				d[i][j]=99999;
		for(i=0;i<n;i++)
		{	
			scanf("%d%d%d%d",&x,&y,&b,&l);
			if(b==1)
			{
				for(j=0;j<l;j++)
				{
					a[x][y+j][3]=99999;
					a[x-1][y+j][1]=99999;
				}
			}
			else
			{
				for(j=0;j<l;j++)
				{
					a[x+j][y][2]=99999;
					a[x+j][y-1][0]=99999;
				}
			}
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&b);
			if(b==1)
			{
				a[x][y][3]=1;
				a[x-1][y][1]=1;
			}
			else
			{
				a[x][y][2]=1;
				a[x][y-1][0]=1;
			}
		}
		scanf("%lf%lf",&xx,&yy);
		if(xx<1||yy<1||xx>198||y>198)
		{
			printf("0\n");
			continue;
		}
		x=int(xx);
		y=int(yy);
		bfs();
		if(d[0][0]==99999)
			printf("-1\n");
		else
			printf("%d\n",d[0][0]);
	}
	return 0;
}

				

