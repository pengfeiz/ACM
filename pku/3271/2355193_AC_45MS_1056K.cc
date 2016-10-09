#include <iostream>
using namespace std;

#define MAX 31

int s[MAX][MAX],t;
__int64 c[MAX][MAX];
bool a[MAX*MAX][MAX*MAX],b[MAX][MAX];
int n,m,x1,y1,x2,y2,q;

struct gao
{int x,y;}z[8]={1,2,2,1,1,-2,-2,1,-1,2,2,-1,-1,-2,-2,-1},d[MAX*MAX],dd[MAX*MAX];


void init()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&s[i][j]);
}


void dosth(int num,int x,int y)
{
	int i,xx,yy;
	for(i=0;i<8;i++)
	{
		xx=x+z[i].x;
		yy=y+z[i].y;
		if(xx<0||xx>=n||yy<0||yy>=m)
			continue;
		if(s[xx][yy]==0)
			a[num][xx*m+yy]=a[xx*m+yy][num]=true;
		else if(s[xx][yy]==1&&!b[xx][yy])
		{
			b[xx][yy]=true;
			dosth(num,xx,yy);
		}
	}
}

		
void ready()
{
	int xx,yy,i,j,k;
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(s[i][j]==3)
			{
				s[i][j]=0;
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
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			memset(b,0,sizeof(b));
			if(s[i][j]>0)
				continue;
			for(k=0;k<8;k++)
			{
				xx=i+z[k].x;
				yy=j+z[k].y;
				if(xx<0||xx>=n||yy<0||yy>=m)
					continue;
				if(s[xx][yy]==0)
					a[i*m+j][xx*m+yy]=a[xx*m+yy][i*m+j]=true;
				else if(s[xx][yy]==1&&!b[xx][yy])
				{
					b[xx][yy]=true;
					dosth(i*m+j,xx,yy);
				}
			}
		}
}


void solve()
{
	int i,j,d1,d2,q,p,k;
	memset(c,0,sizeof(c));
	memset(s,127,sizeof(s));
	c[x2][y2]=1;
	s[x2][y2]=0;
	t=0;
	d1=1;
	d[0].x=x2;
	d[0].y=y2;
	while(d1&&!c[x1][y1])
	{
		d2=0;
		t++;
		for(i=0;i<d1;i++)
		{
			q=d[i].x*m+d[i].y;
			for(j=0;j<n;j++)
				for(k=0;k<m;k++)
				{
					p=j*m+k;
					if(a[q][p]&&s[j][k]>=t)
					{
						c[j][k]+=c[d[i].x][d[i].y];
						if(s[j][k]>t)
						{
							s[j][k]=t;
							dd[d2].x=j;
							dd[d2++].y=k;
						}
					}
				}
		}
		d1=d2;
		for(i=0;i<d1;i++)
		{
			d[i].x=dd[i].x;
			d[i].y=dd[i].y;
		}
	}
	if(!c[x1][y1])
		printf("-1\n");
	else
		printf("%d\n%I64d\n",t-1,c[x1][y1]);
}


int main()
{
	//freopen("in.txt","r",stdin);
	init();
	ready();
	solve();
	return 0;
}