#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	__int64 n,i;
	int nn;
	cin>>nn;
	while(nn-->0)
	{
		scanf("%I64d",&n);
		for(i=0;i<=100000;i++)
			if(sqrt(n-i*i)==ceil(sqrt(n-i*i)))
				break;
		if(i<=100000)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
