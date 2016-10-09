#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double w,s,c,r;
	int n;
	cin>>s>>r>>c>>n;
	while(n-->0)
	{
		cin>>w;
		printf("%.3f\n",s*r/sqrt(r*r+1/(w*w*c*c)));
	}
	return 0;
}

