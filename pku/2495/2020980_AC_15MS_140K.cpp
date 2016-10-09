#include <iostream>
using namespace std;
int main()
{
	int x1,y1,x2,y2,nn,t=0;
	cin>>nn;
	while(nn-->0)
	{
		t++;
		cout<<"Scenario #"<<t<<":\n";
		cin>>x1>>y1>>x2>>y2;
		if((abs(x1-x2)%2==1&&abs(y1-y2)%2==0)||(abs(x1-x2)%2==0&&abs(y1-y2)%2==1))
			cout<<"1\n\n";
		else
			cout<<"0\n\n";
	}
	return 0;
}
