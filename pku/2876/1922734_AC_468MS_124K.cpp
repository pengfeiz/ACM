#include <iostream>
#include <math.h>
using namespace std;
void cc(int n)
{
	long i;
	if(n==0)
		cout<<"-";
	else if(n==1)
		cout<<"- -";
	else
	{
		cc(n-1);
		for(i=0;i<pow(3,(double)n-1);i++)
			cout<<" ";
		cc(n-1);
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		cc(n);
		cout<<endl;
	}
	return 0;
}