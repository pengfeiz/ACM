#include <iostream>
using namespace std;
double ji(double n)
{
	double i,m=1;
	for(i=2;i<=n;i++)
		m*=i;
	return m;
}
int main()
{
	cout<<"n e\n";
	cout<<"- -----------\n";
	cout<<"0 1\n";
	cout<<"1 2\n";
	cout<<"2 2.5\n";
	double t,q;
	q=2.5;
	for(t=3;t<=9;t++)
		printf("%d %.9f\n",(int)t,q+=1/ji(t));
	return 0;
}