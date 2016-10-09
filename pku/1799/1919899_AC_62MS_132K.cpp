#include <stdio.h>
#include <iostream>
#include <math.h>
#define pi 3.1415926535
using namespace std;
main()
{
	int nn,time;
	double rr,n;
	cin>>nn;
	for(time=1;time<=nn;time++)
	{
		if(time-1)
			cout<<"\n";
		cout<<"Scenario #"<<time<<":\n";
		cin>>rr>>n;
		n=pi/n;
		n=sin(n);
		printf("%.3f\n",n*rr/(1+n));
	}
	return 0;
}


