#include <iostream>
using namespace std;
int num[1000000];
int main()
{
	long n,k,p,q;
	cin>>n;
	for(k=0;k<n;k++)
	{
		scanf("%ld%ld",&p,&q);
		num[k]=p+q;
	}
	for(k=n-1;k>0;k--)
	{
		num[k-1]+=num[k]/10;
		num[k]%=10;
	}
	for(k=0;k<n;k++)
		printf("%ld",num[k]);
	cout<<endl;
	return 0;
}