#include <iostream>
using namespace std;

#define MAX 32

struct gao
{
	int x,y,z;
};

char	s[MAX];
int		l,r,c,d[MAX][MAX][MAX],x1,y1,z1,x2,y2,z2,n,nn;
bool    a[MAX][MAX][MAX];
gao f[MAX*MAX*MAX],e[MAX*MAX*MAX];

bool build()
{
	int i,j,k;
	scanf("%d%d%d",&l,&r,&c);
	if(!(r||c||l))
		return false;
	memset(d,127,sizeof(d));
	memset(a,0,sizeof(a));
	for(i=1;i<=l;i++)
		for(j=1;j<=r;j++)
		{
			scanf("%s",s+1);
			for(k=1;k<=c;k++)
			{
				if(s[k]=='.')
					a[i][j][k]=true;
				else if(s[k]=='S')
				{
					x1=i;
					y1=j;
					z1=k;
					a[i][j][k]=true;
				}
				else if(s[k]=='E')
				{
					x2=i;
					y2=j;
					z2=k;
					a[i][j][k]=true;
				}
			}
		}
	return true;
}


void bfs()
{
	int i,t=0;
	n=1;
	e[0].x=x1;
	e[0].y=y1;
	e[0].z=z1;
	while(n&&d[x2][y2][z2]>99999)
	{
		nn=0;
		t++;
		for(i=0;i<n;i++)
		{
			d[e[i].x][e[i].y][e[i].z]=t-1;
			if(a[e[i].x-1][e[i].y][e[i].z]&&d[e[i].x-1][e[i].y][e[i].z]>t)
			{
				a[e[i].x-1][e[i].y][e[i].z]=false;
				f[nn].x=e[i].x-1;
				f[nn].y=e[i].y;
				f[nn].z=e[i].z;
				nn++;
			}
			if(a[e[i].x+1][e[i].y][e[i].z]&&d[e[i].x+1][e[i].y][e[i].z]>t)
			{
				a[e[i].x+1][e[i].y][e[i].z]=false;
				f[nn].x=e[i].x+1;
				f[nn].y=e[i].y;
				f[nn].z=e[i].z;
				nn++;
			}
			if(a[e[i].x][e[i].y-1][e[i].z]&&d[e[i].x][e[i].y-1][e[i].z]>t)
			{
				a[e[i].x][e[i].y-1][e[i].z]=false;
				f[nn].x=e[i].x;
				f[nn].y=e[i].y-1;
				f[nn].z=e[i].z;
				nn++;
			}
			if(a[e[i].x][e[i].y+1][e[i].z]&&d[e[i].x][e[i].y+1][e[i].z]>t)
			{
				a[e[i].x][e[i].y+1][e[i].z]=false;
				f[nn].x=e[i].x;
				f[nn].y=e[i].y+1;
				f[nn].z=e[i].z;
				nn++;
			}
			if(a[e[i].x][e[i].y][e[i].z-1]&&d[e[i].x][e[i].y][e[i].z-1]>t)
			{
				a[e[i].x][e[i].y][e[i].z-1]=false;
				f[nn].x=e[i].x;
				f[nn].y=e[i].y;
				f[nn].z=e[i].z-1;
				nn++;
			}
			if(a[e[i].x][e[i].y][e[i].z+1]&&d[e[i].x][e[i].y][e[i].z+1]>t)
			{
				a[e[i].x][e[i].y][e[i].z+1]=false;
				f[nn].x=e[i].x;
				f[nn].y=e[i].y;
				f[nn].z=e[i].z+1;
				nn++;
			}
		}
		memcpy(e,f,nn*sizeof(gao));
		n=nn;
	}
}

int	main()
{
	while(build())
	{
		bfs();
		if(d[x2][y2][z2]<999999)
			printf("Escaped in %d minute(s).\n",d[x2][y2][z2]);
		else printf("Trapped!\n");
	}
	return 0;
}