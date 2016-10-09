#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long x,y,nn,p;
	cin>>nn;
	while(nn-->0)
	{
		cin>>x>>y;
		y-=x;
		p=(long)sqrt(double(y));
		if(p*p==y)
			cout<<2*p-1<<endl;
		else if(p*p+p<y)
			cout<<2*p+1<<endl;
		else
			cout<<2*p<<endl;
	}
	return 0;
}

		
	