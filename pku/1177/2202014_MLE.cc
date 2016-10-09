#include <iostream>
#include <algorithm>

using namespace std;
#define hehe 5001

struct gao
{
	int x,y;
}a[hehe];

int c[hehe],d[hehe],ans,n,p,q;
bool b[hehe][hehe];

bool com(int a,int b)
{
	return a<b;
}

void dosth(int x)
{
	int i,j,x1,y1,x2,y2;
	for(i=0;i<p;i++)
	{
		if(a[x].x==c[i])
		{
			x1=i;
			break;
		}
	}
	for(i=0;i<p;i++)
	{
		if(a[x+1].x==c[i])
		{
			x2=i;
			break;
		}
	}
	for(i=0;i<q;i++)
	{
		if(a[x].y==d[i])
		{
			y1=i;
			break;
		}
	}
	for(i=0;i<q;i++)
	{
		if(a[x+1].y==d[i])
		{
			y2=i;
			break;
		}
	}
	for(i=x1;i<x2;i++)
		for(j=y1;j<y2;j++)
			b[i][j]=true;
}

void judge()
{
	int i,j;
	for(i=0;i<p-1;i++)
		for(j=0;j<q-1;j++)
		{
			if(b[i][j])
			{
				if(i==0||!b[i-1][j])
					ans+=d[j+1]-d[j];
				if(j==0||!b[i][j-1])
					ans+=c[i+1]-c[i];
				if(!b[i+1][j])
					ans+=d[j+1]-d[j];
				if(!b[i][j+1])
					ans+=c[i+1]-c[i];
			}
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	for(i=0;i<2*n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=0;i<2*n;i++)
	{
		c[i]=a[i].x;
		d[i]=a[i].y;
	}
	sort(c,c+2*n,com);
	sort(d,d+2*n,com);
	p=q=0;
	for(i=2*n-1;i>=0;i--)
	{
		a[i].x-=c[0];
		a[i].y-=d[0];
		c[i]-=c[0];
		d[i]-=d[0];
	}
	c[2*n]=d[2*n]=-1;
	for(i=0;i<2*n;i++)
		if(c[i]!=c[i+1])
			c[p++]=c[i];
	for(i=0;i<2*n;i++)
		if(d[i]!=d[i+1])
			d[q++]=d[i];
	ans=0;
	for(i=0;i<2*n;i+=2)
		dosth(i);
	judge();
	printf("%d\n",ans);
	return 0;
}
