#include <iostream>
#define MAX 6000;
using namespace std;
int main()
{
	int i,n,a,b;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		if((a-b)==2&&a>=2&&b>=0)
		{
			if(a%2==0)
				cout<<2*a-2<<endl;
			else
				cout<<2*a-3<<endl;
		}
		else if(a==b&&a>=0&&b>=0)
		{
			if(a%2==0)
				cout<<2*a<<endl;
			else
				cout<<2*a-1<<endl;
		}
		else
			cout<<"No Number\n";
	}
	return 0;
}
