#include <iostream>
using namespace std;
int main()
{
	int a,b,c,n,i;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		for(a=2;a<=n;a++)
			for(b=a;b<=n;b++)
				for(c=b;c<=n;c++)
				{
					if(i*i*i==a*a*a+b*b*b+c*c*c)
						cout<<"Cube = "<<i<<", Triple = ("<<a<<","<<b<<","<<c<<")\n";
					else if(i*i*i<a*a*a+b*b*b+c*c*c)
						break;
				}
	}
	return 0;
}