#include <iostream>
#include <stdio.h>
using namespace std;
double c[5000];
int main()
{
	int n,i;
	double tt=0;
	cin>>n;
	cin>>c[0]>>c[n+1];
	for(i=1;i<=n;i++)
		cin>>c[i];
	for(i=1;i<=n;i++)
		tt-=c[i]*2*(n-i+1);
	tt+=c[n+1]+n*c[0];
	printf("%.2f\n",tt/(n+1));
	return 0;
}


