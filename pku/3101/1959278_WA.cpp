#include <iostream>
using namespace std;
#define MAX 1000
__int64 a[MAX];
__int64 gcd(__int64 a,__int64 b)
{
	__int64 p;
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
__int64 lcm(__int64 a,__int64 b)
{
	return a*b/gcd(a,b);
}
int main()
{
	__int64 n,i,w,m,j,w1,m1,k;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		if(a[i]!=a[0])
			k=i;
	}
	w=a[0]*a[k];
	m=abs(a[k]-a[0]);
	j=gcd(w,m);
	w/=j;
	m/=j;
	for(i=1;i<n;i++)
	{
		if(a[i]==a[0]||a[i]==a[k])
			continue;
		w1=lcm(abs(a[i]-a[0]),a[i]*a[0]);
		m1=gcd(a[i]*a[0],abs(a[i]-a[0]));
		j=gcd(w1,m1);
		w1/=j;
		m1/=j;
		w=lcm(w1,w);
		m=gcd(m1,m);
	}
	if(w%2==0)
		printf("%I64d %I64d\n",w/2,m);
	else
		printf("%I64d %I64d\n",w,2*m);
	return 0;
}
