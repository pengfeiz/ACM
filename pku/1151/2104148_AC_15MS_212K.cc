#include <iostream>
#include <algorithm>

using namespace std;
#define hehe 200

struct gao
{
	double x,y;
}a[hehe];

double c[hehe],d[hehe],ans;
int n;
bool b[hehe][hehe];

bool com(double a,double b)
{
	return a<b;
}

void dosth(int p)
{
	int i,j,x1,y1,x2,y2;
	for(i=0;i<2*n;i++)
	{
		if(a[p].x==c[i])
			x1=i;
		if(a[p+1].x==c[i])
			x2=i;
	}
	for(i=0;i<2*n;i++)
	{
		if(a[p].y==d[i])
			y1=i;
		if(a[p+1].y==d[i])
			y2=i;
	}
	for(i=x1;i<x2;i++)
		for(j=y1;j<y2;j++)
			b[i][j]=true;
}

void add(int x,int y)
{
	double l1,l2;
	l1=c[x+1]-c[x];
	l2=d[y+1]-d[y];
	if(!l1||!l2)
		return;
	ans+=l2*l1;
}
	
void sum()
{
	int i,j;
	for(i=0;i<2*n-1;i++)
		for(j=0;j<2*n-1;j++)
			if(b[i][j])
				add(i,j);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,time=0;
	while(scanf("%d",&n),n)
	{
		if(time)
			printf("\n");
		time++;
		printf("Test case #%d\n",time);
		ans=0;
		memset(b,0,sizeof(b));
		for(i=0;i<2*n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		for(i=0;i<2*n;i++)
		{
			c[i]=a[i].x;
			d[i]=a[i].y;
		}
		sort(c,c+2*n,com);
		sort(d,d+2*n,com);
		for(i=0;i<2*n;i++)
		{
			a[i].x-=c[0];
			a[i].y-=d[0];
		}
		for(i=1;i<2*n;i++)
		{
			c[i]-=c[0];
			d[i]-=d[0];
		}
		c[0]=d[0]=0;
		for(i=0;i<2*n;i+=2)
			dosth(i);
		sum();
		printf("Total explored area: %.2lf\n",ans);
	}
	return 0;
}
