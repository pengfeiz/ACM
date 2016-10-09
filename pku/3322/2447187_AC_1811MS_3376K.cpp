#include <iostream>
using namespace std;

#define MAX 503

int a[MAX][MAX][3],n,m,x1,y1,nn,x2,y2;
char s[MAX][MAX];

struct gao
{
	int x,y,n;
}b[MAX*MAX],bb[MAX*MAX],z0[4]={1,0,2,0,1,1,-2,0,2,0,-2,1},z1[4]={1,0,1,0,2,0,-1,0,1,0,-1,0},z2[4]={2,0,0,0,1,2,-1,0,0,0,-1,2},zz[3]={0,0,0,0,1,0,1,0,0};

int n1,n2;

bool init()
{
	int i,j;
	memset(s,0,sizeof(s));
	memset(a,127,sizeof(a));
	scanf("%d%d",&n,&m);
	if(!(n||m))
		return false;
	for(i=0;i<n;i++)
		scanf("%s",s[i]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(s[i][j]=='O')
			{
				s[i][j]='.';
				x2=i;
				y2=j;
			}
			if(s[i][j]=='X')
			{
				s[i][j]='.';
				x1=i;
				y1=j;
				if(s[i+1][j]=='X')
				{
					nn=2;
					s[i+1][j]='.';
				}
				else if(s[i][j+1]=='X')
				{
					nn=1;
					s[i][j+1]='.';
				}
				else
					nn=0;
			}		
		}
	return true;
}


void bfs()
{
	int i,j,t=0;
	gao p,q;
	n1=1;
	b[0].x=x1;
	b[0].y=y1;
	b[0].n=nn;
	a[x1][y1][nn]=t;
	while(n1&&a[x2][y2][0]>99999)
	{
		t++;
		n2=0;
		for(i=0;i<n1;i++)
		{
			if(b[i].n==0)
			{
				for(j=0;j<4;j++)
				{
					p.x=b[i].x+z0[j].x;
					p.y=b[i].y+z0[j].y;
					p.n=z0[j].n;
					q.x=p.x+zz[p.n].x;
					q.y=p.y+zz[p.n].y;
					if(p.x<0||p.y<0||p.x>=n||p.y>=m)
						continue;
					if(s[p.x][p.y]=='#')
						continue;
					if(s[q.x][q.y]=='#')
						continue;
					if(q.x==p.x&&q.y==p.y&&s[p.x][p.y]=='E')
						continue;
					if(a[p.x][p.y][p.n]>t)
					{
						a[p.x][p.y][p.n]=t;
						bb[n2].x=p.x;
						bb[n2].y=p.y;
						bb[n2++].n=p.n;
					}
				}
			}
			else if(b[i].n==1)
			{
				for(j=0;j<4;j++)
				{
					p.x=b[i].x+z1[j].x;
					p.y=b[i].y+z1[j].y;
					p.n=z1[j].n;
					q.x=p.x+zz[p.n].x;
					q.y=p.y+zz[p.n].y;
					if(p.x<0||p.y<0||p.x>=n||p.y>=m)
						continue;
					if(s[p.x][p.y]=='#')
						continue;
					if(s[q.x][q.y]=='#')
						continue;
					if(q.x==p.x&&q.y==p.y&&s[p.x][p.y]=='E')
						continue;
					if(a[p.x][p.y][p.n]>t)
					{
						a[p.x][p.y][p.n]=t;
						bb[n2].x=p.x;
						bb[n2].y=p.y;
						bb[n2++].n=p.n;
					}
				}
			}
			else
			{
				for(j=0;j<4;j++)
				{
					p.x=b[i].x+z2[j].x;
					p.y=b[i].y+z2[j].y;
					p.n=z2[j].n;
					q.x=p.x+zz[p.n].x;
					q.y=p.y+zz[p.n].y;
					if(p.x<0||p.y<0||p.x>=n||p.y>=m)
						continue;
					if(s[p.x][p.y]=='#')
						continue;
					if(s[q.x][q.y]=='#')
						continue;
					if(q.x==p.x&&q.y==p.y&&s[p.x][p.y]=='E')
						continue;
					if(a[p.x][p.y][p.n]>t)
					{
						a[p.x][p.y][p.n]=t;
						bb[n2].x=p.x;
						bb[n2].y=p.y;
						bb[n2++].n=p.n;
					}
				}
			}
		}
		n1=n2;
		for(i=0;i<n1;i++)
		{
			b[i].x=bb[i].x;
			b[i].y=bb[i].y;
			b[i].n=bb[i].n;
		}
	}
}


int main()
{
	//freopen("in.txt","r",stdin);
	while(init())
	{
		bfs();
		if(a[x2][y2][0]>999999)
			printf("Impossible\n");
		else
			printf("%d\n",a[x2][y2][0]);
	}
	return 0;
}
