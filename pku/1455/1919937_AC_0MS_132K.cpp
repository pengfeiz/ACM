#include <iostream>
using namespace std;
int main()
{
	long nn,n,i,min,tt;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n;
		tt=n*(n-1)/2;
		min=tt;
		for(i=n;i>1;i--)
		{
			tt+=1+n-i-i;
			if(tt<min)
				min=tt;
		}
		cout<<min<<endl;
	}
	return 0;
}
