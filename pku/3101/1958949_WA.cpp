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
	__int64 n,i,w,m;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	w=m=a[0];
	for(i=1;i<n;i++)
	{
		w=lcm(w,a[i]);
		m=gcd(m,a[i]);
	}
	if(w%2==0)
		printf("%I64d %I64d\n",w/2,m);
	else
		printf("%I64d %I64d\n",w,2*m);
	return 0;
}
