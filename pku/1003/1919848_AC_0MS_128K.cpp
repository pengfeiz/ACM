#include <iostream>
using namespace std;
int main()
{
	float l,n,s;
	while(cin>>l&&l!=0)
	{
		n=2;
		s=0;
		while(s<l)
		{
			s+=1/n;
			n++;
		}
		cout<<n-2<<" card(s)\n";
	}
	return 0;
}
