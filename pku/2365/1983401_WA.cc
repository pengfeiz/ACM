#include <iostream>
using namespace std;
int main()
{
	double a[100],c,t;
	int n,i;
	cin>>n>>c;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=t=0;i<n;i++)
		t+=(a[i]-a[(i+1)%n])*(a[i]-a[(i+1)%n]);
	t+=2*3.1415926*c;
	printf("%.2lf\n",t);
	return 0;
}