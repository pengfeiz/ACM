#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a,b,c;
	cin>>a>>b>>c;
	cout<<long(pow(1+a/100,c)*b)<<endl;
	return 0;
}