#include <iostream>
using namespace std;

#define MAX 31


struct gao
{
	int x1,y1,x2,y2;
}c[MAX];

int n;

struct gao2
{
	int x,y;
}b[MAX];

bool q[MAX],a[MAX][MAX];
int d[MAX],m,z[MAX],y[MAX],t,maxx,h[MAX];


bool find(int x)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=n;i++)
		if(a[x][i]&&(!y[i]||find(y[i])))
		{
			if(!y[i])
				t++;
			z[x]=i;
			y[i]=x;
			return true;
		}
	return false;
}


int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,tim=0;
	while(scanf("%d",&n),n)
	{
		m=maxx=0;
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		for(i=1;i<=n;i++)
			scanf("%d%d%d%d",&c[i].x1,&c[i].x2,&c[i].y1,&c[i].y2);
		for(i=1;i<=n;i++)
			scanf("%d%d",&b[i].x,&b[i].y);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(b[i].x<=c[j].x2&&b[i].x>=c[j].x1&&b[i].y<=c[j].y2&&b[i].y>=c[j].y1)
				{
					a[j][i]=true;
					m++;
				}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(a[i][j])
				{
					t=0;
					memset(y,0,sizeof(y));
					memset(z,0,sizeof(z));
					a[i][j]=false;					
					for(k=1;k<=n;k++)
					{
						memset(q,0,sizeof(q));
						find(k);
					}
					if(t>maxx)
					{
						for(k=1;k<=n;k++)
							d[k]=z[k];
						maxx=t;
					}
					else if(t==maxx)
					{
						for(k=1;k<=n;k++)
							if(d[k]!=z[k])
								d[k]=0;
					}
					a[i][j]=true;
				}
			}
		printf("Heap %d\n",++tim);
		maxx=0;
		for(i=1;i<=n;i++)
			if(d[i])
				maxx++;
		if(!maxx)
			printf("none");
		else
		{
			j=0;
			for(i=1;i<=n;i++)
				if(d[i])
				{
					if(j)
						printf(" ");
					j++;
					printf("(%c,%d)",i+'A'-1,d[i]);
				}
		}
		printf("\n\n");
	}
	return 0;
}
