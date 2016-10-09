#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a[100][2],c,t;
	int n,i;
	cin>>n>>c;
	for(i=0;i<n;i++)
		cin>>a[i][0]>>a[i][1];
	for(i=t=0;i<n;i++)
		t+=sqrt((a[i][0]-a[(i+1)%n][0])*(a[i][0]-a[(i+1)%n][0])+(a[i][1]-a[(i+1)%n][1])*(a[i][1]-a[(i+1)%n][1]));
	t+=2*3.1415926*c;
	printf("%.2lf\n",t);
	getchar();
	return 0;
}