#include <iostream>
using namespace std;
long a[75000];
int main()
{
	long q,t,i;
	q=1;
	a[0]=1;
	for(i=1;i<75000;i++)
	{
		a[i]=a[i-1]+q;
		q+=a[i];
		a[i]%=100000;
	}
	cin>>t;
	while(t-->0)
	{
		scanf("%ld",&q);
		printf("%ld\n",a[(q-1)%75000]);
	}
	return 0;
}
