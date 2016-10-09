#include <iostream>
using namespace std;
int main()
{
	double x,y,z;
	int n,i;
	scanf("%lf%lf%lf%d",&x,&y,&z,&n);
	for(i=0;i<n;i++)
		printf("%.8lf %.8lf %.8lf %.8lf %.8lf %.8lf\n",0.0,0.0,i*z/n,x,y,(i+1)*z/n);
	return 0;
}