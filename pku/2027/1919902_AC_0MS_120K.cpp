#include <iostream>
using namespace std;
int main()
{
	int n,i;
	double a,b;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a<b)
			cout<<"NO BRAINS\n";
		else
			cout<<"MMM BRAINS\n";
	}
	return 0;
}