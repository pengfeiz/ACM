#include <iostream>
using namespace std;
int main()
{
	int nn,i;
	long t;
	cin>>nn;
	for(i=1;i<=nn;i++)
	{
		cout<<i<<" ";
		cin>>t;
		cout<<t/25<<" QUARTER(S), ";
		t=t%25;
		cout<<t/10<<" DIME(S), ";
		t%=10;
		cout<<t/5<<" NICKEL(S), ";
		t%=5;
		cout<<t<<" PENNY(S)\n";
	}
	return 0;
}
