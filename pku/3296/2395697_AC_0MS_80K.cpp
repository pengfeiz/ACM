#include <iostream>
using namespace std;
int main()
{
	int n,i;
	double a,b,c,d,t,p; 
	while(scanf("%d",&n)&&n)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		if(a+b<c)
		{
			printf("0\n");
			continue;
		}
		t=a+b-c;
		p=t/n;
		if(p>d-c)
			p=d-c;
		if(p>=b-c)
		{
			printf("%d %.2lf",n,p-b+c);
			for(i=1;i<n;i++)
				printf(" %.2lf",p);
		}
		else
		{
			printf("%d 0.00",n);
			p=a/(n-1);
			for(i=1;i<n;i++)
				printf(" %.2lf",p);
		}
		printf("\n");
	}
	return 0;
}
