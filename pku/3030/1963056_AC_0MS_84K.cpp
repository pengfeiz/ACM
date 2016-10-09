#include <iostream>
using namespace std;
int main()
{
	int nn;
	long a1,a2,a3;
	cin>>nn;
	while(nn-->0)
	{
		cin>>a1>>a2>>a3;
		if(a1>a2-a3)
			cout<<"do not advertise";
		else if(a1==a2-a3)
			cout<<"does not matter";
		else
			cout<<"advertise";
		cout<<endl;
	}
	return 0;
}
