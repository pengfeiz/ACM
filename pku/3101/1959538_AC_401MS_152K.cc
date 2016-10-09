#include <iostream>
using namespace std;
#define MAX 1000
long a[MAX];
long w[MAX*MAX];
long gcd(long a,long b)
{
	long p;
	if(a<b)
		swap(a,b);
	while(a%b!=0)
	{
		p=a%b;
		a=b;
		b=p;
	}
	return b;
}
long lcm(long a,long b)
{
	return a*b/gcd(a,b);
}
long gcdd(long b)
{
	long r=0,i;
	for(i=w[0];i>0;i--) 
	{
		r=r*10+w[i];
		r=r%b;
	}
	if(r==0)
		return b;
	return gcd(b,r);
} 
void chu(long x)
{
	long i,t=0;
	for(i=w[0];i>1;i--)
	{
		w[i-1]+=10*(w[i]%x);
		w[i]/=x;
	}
	w[1]/=x;
	while(w[w[0]]==0)
		w[0]--;
}
void lcmm(long b)
{
	long r=0,x=gcdd(b),i;
	for(i=1;i<=w[0];i++)
		w[i]*=b;
	for(i=1;i<w[0];i++)
	{
		if(w[i]>0)
		{
			w[i+1]+=w[i]/10;
			w[i]%=10;
		}
	}
	while(w[w[0]]>0)
	{
		w[0]++;
		w[w[0]]=w[w[0]-1]/10;
		w[w[0]-1]%=10;
	}
	w[0]--;
	chu(x);
}
int main()
{
	long n,i,m,j,w1,m1,k;
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
		if(a[i]!=a[0])
			k=i;
	}
	m1=a[0]*a[k];
	w[0]=0;
	while(m1>0)
	{
		w[w[0]+1]=m1%10;
		m1/=10;
		w[0]++;
	}
	m=abs(a[k]-a[0]);
	j=gcdd(m);
	chu(j);
	m/=j;
	for(i=1;i<n;i++)
	{
		if(a[i]==a[0]||a[i]==a[k])
			continue;
		m1=gcd(a[i]*a[0],abs(a[i]-a[0]));
		w1=(a[i]*a[0])/m1;
		m1=abs(a[i]-a[0])/m1;
		lcmm(w1);
		m=gcd(m1,m);
	}
	if(w[1]%2==0)
		chu(2);
	else
		m*=2;
	for(i=w[0];i>0;i--)
		printf("%ld",w[i]);
	printf(" %ld\n",m);
	return 0;
}
