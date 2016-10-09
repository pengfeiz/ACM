#include <iostream>
#include <math.h>
using namespace std;
#define MAX 60

struct gao
{
	double x,y;
}a[MAX];

bool b[MAX];
int n;
double t;

double ll(double x)
{return x*x;}

void dosth(int x,int r,double l,int tt)
{
	if(l>=t)
		return;
	int i;
	if(r==0)
	{
		if(x==n-1)
		{
			dosth(n-1,1,l,tt+1);
			return;
		}
		for(i=x+1;i<n;i++)
		{
			b[i]=true;
			dosth(i,0,l+sqrt(ll(a[i].x-a[x].x)+ll(a[i].y-a[x].y)),tt+1);
			b[i]=false;
		}
	}
	else
	{
		int q;
		q=n-1;
		for(i=n-2;i>=0;i--)
		{
			if(!b[i])
			{
				l+=sqrt(ll(a[i].x-a[q].x)+ll(a[i].y-a[q].y));
				q=i;
			}
			if(l>=t)
				return;
		}
		if(l<t)
			t=l;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		t=99999999.0;
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		dosth(0,0,0,0);
		printf("%.2lf\n",t);
	}
	return 0;
}