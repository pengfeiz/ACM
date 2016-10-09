#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.14159265
int main()
{
	double a,b,c,he;
	int nn;
	cin>>nn;
	while(nn-->0)
	{
		cin>>a>>b>>c;
		he=asin(c/sqrt((a-b)*(a-b)-b*b))+asin(b/(a-b));
		cout<<int(pi/he)<<endl;
	}
	return 0;
}
