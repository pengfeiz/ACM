#include <iostream>
using namespace std;

#define MAX 50

int a[MAX][MAX][3],x1,y1,nn,x2,y2;
char s[MAX][MAX];
char c;
__int64 n,m;

struct gao
{
	int x,y,n;
}b[MAX*MAX],bb[MAX*MAX],z0[4]={1,0,2,0,1,1,-2,0,2,0,-2,1},z1[4]={1,0,1,0,2,0,-1,0,1,0,-1,0},z2[4]={2,0,0,0,1,2,-1,0,0,0,-1,2},zz[3]={0,0,0,0,1,0,1,0,0};

int n1,n2;


void init()
{
	int i,j;
	memset(s,0,sizeof(s));
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			s[i][j]='.';
	if(c=='U')
		nn=0;
	else if(c=='H')
		nn=1;
	else
		nn=2;
	x2=y2=25;
	x1=x2+n;
	y1=y2+m;
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
					if(p.x<0||p.y<0||p.x>=MAX||p.y>=MAX)
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
					if(p.x<0||p.y<0||p.x>=MAX||p.y>=MAX)
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
					if(p.x<0||p.y<0||p.x>=MAX||p.y>=MAX)
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


void dosthh()
{
	init();
	memset(a,127,sizeof(a));
	bfs();
	printf("%d",a[x2][y2][0]);
}


__int64 dosth(__int64 n,__int64 m)
{
	if(n<0)
		n*=-1;
	if(m<0)
		m*=-1;
	if(n>m)
		swap(n,m);
	if(n==0)
		return 2*((m+2)/3)+m%3;
	else if(n==1)
	{
		if(m<=2)
			return 6;
		return dosth(0,m)+1;
	}
	else if(n==2)
	{
		if(m%3==0)
			return dosth(n-1,m)+1;
		return dosth(n-1,m);
	}
	else
	{
		if(n%3)
			return dosth(n-n%3,m)+n%3;
		return m%3+(m-n)/3*2+n/3*4;
	}
}

__int64 minn(__int64 a,__int64 b)
{return a<b?a:b;}

int main()
{
//	freopen("in.txt","r",stdin);
	__int64 q;
//	c='H';
//	for(n=0;n<20;n++)
//	{
//		for(m=0;m<20;m++)
	while(scanf("%c%I64d%I64d",&c,&n,&m)!=EOF)
	{
		getchar();
		if(n<5&&m<5)
			dosthh();
		else if(c=='U')
			printf("%I64d",dosth(n,m));
		else if(c=='H')
		{
			q=minn(dosth(n,m-1),dosth(n,m+2))+1;
			q=minn(q,dosth(n-1,m-1)+2);
			q=minn(q,dosth(n-1,m+2)+2);
			q=minn(q,dosth(n+1,m-1)+2);
			q=minn(q,dosth(n+1,m+2)+2);
			q=minn(q,dosth(n-2,m-1)+3);
			q=minn(q,dosth(n-2,m+2)+3);
			q=minn(q,dosth(n+2,m-1)+3);
			q=minn(q,dosth(n+2,m+2)+3);
			printf("%I64d",q);
		}
		else
		{
			q=minn(dosth(n+2,m),dosth(n-1,m))+1;
			q=minn(q,dosth(n-1,m-1)+2);
			q=minn(q,dosth(n+2,m-1)+2);
			q=minn(q,dosth(n-1,m+1)+2);
			q=minn(q,dosth(n+2,m+1)+2);
			q=minn(q,dosth(n-1,m-2)+3);
			q=minn(q,dosth(n+2,m-2)+3);
			q=minn(q,dosth(n-1,m+2)+3);
			q=minn(q,dosth(n+2,m+2)+3);
			printf("%I64d",q);
		}
		printf("\n");
	}
	return 0;
}

