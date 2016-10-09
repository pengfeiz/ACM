#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int main()
{
	ifstream cin("input2.txt");
	__int64 n,i;
	int nn;
	cin>>nn;
	while(nn-->0)
	{
		scanf("%I64d",&n);
		for(i=0;i<=1000000;i++)
			if(sqrt(n-i*i)==ceil(sqrt(n-i*i)))
				break;
		if(i<=1000000)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
