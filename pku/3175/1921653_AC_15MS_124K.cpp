#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int n;
	double m,i=0,p=1;
	cin>>n>>m;
	while(n-->0)
	{
		m/=10;
		p/=10;
	}
	i=0;
	while(ceil((i+m)*(i+m))==ceil((i+m+p)*(i+m+p)))
		i++;
	printf("%I64d\n",(__int64)ceil((i+m)*(i+m)));
	return 0;
}
	
