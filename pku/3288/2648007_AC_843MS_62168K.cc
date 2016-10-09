#include <stdio.h>
#include <string.h>
#include <math.h>

int g[2002][2002],d[2002][2002],qx[2002*2002],qy[2002*2002];
int qn,i,p,x,y,xx,yy,X,Y;

void tryy(int a,int b)
{
	if(qx[i]+a>2000)
		return;
	if(qx[i]+a<0)
		return;
	if(qy[i]+b>2000)
		return;
	if(qy[i]+b<0)
		return;
	if(d[qx[i]+a][qy[i]+b]>d[qx[i]][qy[i]]+1)
	{
		d[qx[i]+a][qy[i]+b]=d[qx[i]][qy[i]]+1; 
		qx[qn]=qx[i]+a;
		qy[qn++]=qy[i]+b;
	}
}

int main()
{
	while(scanf("%d",&p),p)
	{
		memset(g,0,sizeof(g));
		memset(d,100,sizeof(d));
		qn=0;
		for(i=0;i<p;i++)
		{
			scanf("%d%d",&x,&y);
			if(!i)
			{
				X=x;
				Y=y;
			}
			xx=x;yy=y;
			g[x][y]=1;
			d[x][y]=0;
			qx[qn]=x;
			qy[qn++]=y;
		}
		scanf("%d",&p);
		for(i=0;i<p;i++)
		{
			scanf("%d%d",&x,&y);
			if(!i)
			{
				X=x;
				Y=y;
			}
			xx=x;yy=y;
			g[x][y]=2;
		}
		for(i=0;i<qn;i++)
		{
			if(g[qx[i]][qy[i]]==2)
			{
				printf("%d\n",d[qx[i]][qy[i]]);
				break;
			}
			tryy(1,0);
			tryy(0,1);
			tryy(-1,0);
			tryy(0,-1);
		}
	}
	return 0;
}