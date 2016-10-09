#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x,y;
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		x=sqrt(x*x+y*y);
		x=x*x*3.1415926/2;
		y=0;
		while(50*y<x)
			y++;
		cout<<"Property "<<i<<": This property will begin eroding in year "<<y<<".\n";
	}
	cout<<"END OF OUTPUT.\n";
	return 0;
}
