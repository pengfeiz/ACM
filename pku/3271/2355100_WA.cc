#include <iostream>
using namespace std;

#define MAX 31

int s[MAX][MAX],t;
__int64 c[MAX][MAX];
bool a[MAX*MAX][MAX*MAX],b[MAX][MAX];
int nn,m,x1,y1,x2,y2,q;

struct gao
{int x,y;}z[8]={1,2,2,1,1,-2,-2,1,-1,2,2,-1,-1,-2,-2,-1},d[MAX*MAX],dd[MAX*MAX];


void init()
{
	int i,j;
	scanf("%d%d",&nn,&m);
	for(i=0;i<nn;i++)
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
		if(xx<0||xx>=nn||yy<0||yy>=m)
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
	for(i=0;i<nn;i++)
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
	for(i=0;i<nn;i++)
		for(j=0;j<m;j++)
		{
			memset(b,0,sizeof(b));
			if(s[i][j]>0)
				continue;
			for(k=0;k<8;k++)
			{
				xx=i+z[k].x;
				yy=j+z[k].y;
				if(xx<0||xx>=nn||yy<0||yy>=m)
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
	int i,d1,d2,p,q,x,y,k;
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
			for(k=0;k<8;k++)
			{
				x=d[i].x+z[k].x;
				y=d[i].y+z[k].y;
				if(x<0||x>=nn||y<0||y>=m)
					continue;
				p=x*m+y;
				if(a[q][p]&&s[x][y]>=t)
				{
					c[x][y]+=c[d[i].x][d[i].y];
					if(s[x][y]>t)
					{
						s[x][y]=t;
						dd[d2].x=x;
						dd[d2++].y=y;
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
//	freopen("in.txt","r",stdin);
	init();
	ready();
	if(a[x1*m+y1][x2*m+y2])
		printf("0\n0\n");
	else
		solve();
	return 0;
}