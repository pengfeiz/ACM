#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

double judge(int n,int c[])
{
	int i,j;
	double t=0;
	bool d[MAX];
	memset(d,0,sizeof(d));
	for(i=0;i<n;i++)
	{
		j=i;
		if(!d[j])
		{
			while(!d[j])
			{
				d[j]=true;
				j=c[j];
			}
			t+=1.0;
		}
	}
	return t;
}

double polya(int n,int p)
{
	int i,m,j,x,c[MAX];
	double t=0;
	for(m=0;m<n;m++)
	{
		for(i=0;i<n;i++)
			c[i]=(i+m)%n;
		t+=pow(p,judge(n,c));
	}
	for(m=0;m<n;m++)
	{
		if(m%2==0)
		{
			j=m/2;
			c[j]=m;
			x=(n-1)/2;
			i=(j+1+n)%n;
			j=(j-1+n)%n;
			while(x--)
			{
				c[i]=j;
				c[j]=i;
				i=(i+1+n)%n;
				j=(j-1+n)%n;
			}
			if(n%2==0)
				c[i]=i;
			t+=(double)pow(p,judge(n,c));
		}
		else
		{
			x=n/2;
			i=(m+n)%n;
			j=(m-1+n)%n;
			while(x--)
			{
				c[i]=j;
				c[j]=i;
				i=(i+1+n)%n;
				j=(j-1+n)%n;
			}
			if(n%2)
				c[i]=i;
			t+=(double)pow(p,judge(n,c));
		}
	}
	t/=2*n;
	return t;	
}

int main()
{
	int n,p;
	while(scanf("%d%d",&n,&p),p||n)
		printf("%.0lf\n",polya(p,n));
	return 0;
}