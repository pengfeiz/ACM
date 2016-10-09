#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int n;
	double m,i=0,p=0.9999999999;
	cin>>n>>m;
	while(n-->0)
	{
		m/=10;
		p/=10;
	}
	i=0;
	while(ceil((i+m)*(i+m))==ceil((i+m+p)*(i+m+p)))
		i++;
	cout<<ceil((i+m)*(i+m))<<endl;
	return 0;
}
	
