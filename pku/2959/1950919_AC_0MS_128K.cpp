#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.14159265
int main()
{
	float a,b,c,he;
	int nn;
	cin>>nn;
	while(nn-->0)
	{
		cin>>a>>b>>c;
		he=asin((b+c)/(a-b));
		cout<<int(pi/he)<<endl;
	}
	return 0;
}
