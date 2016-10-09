#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

struct gao
{
	double x,y;
}a[MAX];

double t1[MAX],t2[MAX];

bool com1(gao a,gao b)
{
	if(a.x<b.x)
		return true;
	if(a.x>b.x)
		return false;
	if(a.y<=b.y)
		return true;
	return false;
}

bool com2(gao a,gao b)
{
	if(a.y<b.y)
		return true;
	if(a.y<b.y)
		return false;
	if(a.x<=b.x)
		return true;
	return false;
}

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int n,i;
	double x,y,m1,m2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf",&x,&y);
		a[i].x=(x-y)/2;
		a[i].y=(x+y)/2;
	}
	m1=m2=0;
	sort(a,a+n,com1);
	for(i=1;i<n;i++)
		m1+=a[i].x-a[0].x;
	t1[0]=m1;
	for(i=1;i<n;i++)
	{
		m1+=(2*i-n)*(a[i].x-a[i-1].x);
		t1[i]=m1;
	}
	sort(a,a+n,com2);
	for(i=1;i<n;i++)
		m2+=a[i].y-a[0].y;
	t2[0]=m2;
	for(i=1;i<n;i++)
	{
		m2+=(2*i-n)*(a[i].y-a[i-1].y);
		t2[i]=m2;
	}
	m1=99999999;
	for(i=0;i<n;i++)
		if(t1[i]+t2[i]<m1)
			m1=t1[i]+t2[i];
	printf("%.0lf\n",m1);
	return 0;
}