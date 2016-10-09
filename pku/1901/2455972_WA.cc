#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


#define MAX 1001
#define MAX2 1000001
#define esp 1e-8


struct gao
{
	double s;
	int n,p;
}a[MAX2],d[MAX];


struct poi
{
	double x,y,z;
	int n;
}b[MAX];


int n,m;
int c[MAX];


double ll(double x)
{return x*x;}
double dis(poi a,poi b)
{return ll(a.x-b.x)+ll(a.y-b.y)+ll(a.z-b.z);}
bool com(gao a,gao b)
{return a.s<b.s;}

int main()
{
	int i,j,t,ma=0;
	double s;
	memset(c,0,sizeof(c));

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf%lf%lf%d",&b[i].x,&b[i].y,&b[i].z,&b[i].n);

	m=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			s=dis(b[i],b[j]);
			d[j].s=s;
			d[j].n=b[j].n;
		}
		sort(d,d+n,com);
		d[n].s=-1;
		t=0;
		for(j=0;j<n;j++)
		{
			j--;
			do
			{
				j++;
				if(d[j].n==b[i].n)
					t++;
				else
					t--;
			}while(fabs(d[j].s-d[j+1].s)<esp);
			a[m].s=d[j].s;
			if(t>0)
				a[m].n=1;
			else
				a[m].n=0;
			a[m].p=i;
			m++;
		}
	}

	sort(a,a+m,com);
	t=0;
	for(i=0;i<m;i++)
	{
		if(t>ma)
		{
			ma=t;
			s=a[i].s;
		}
		if(a[i].n==1)
		{
			if(!c[a[i].p])
			{
				t++;
				c[a[i].p]=true;
			}
		}
		else
		{
			if(c[a[i].p])
			{
				t--;
				c[a[i].p]=false;
			}
		}
	}

	printf("%d\n%.4lf\n",ma,sqrt(s));
	return 0;
}