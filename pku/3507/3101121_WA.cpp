#include <iostream>
#include <algorithm>
using namespace std;

int a[6];

int main()
{
	int i,n;
	int f;
	while(1)
	{
		f=2;
		n=0;
		for(i=0;i<6;i++)
		{
			scanf("%d",&a[i]);
			n+=a[i];
		}
		sort(a,a+6);
		n-=a[0]+a[5];
		for(i=0;i<6;i++)
			if(a[i])
				break;
		if(i==6)
			break;
		while(n)
		{
			if(f==1)
			{
				printf(".");
				f=0;
			}
			if(f==2)
				f=1;
			printf("%d",n/4);
			n=n%4*10;
		}
		printf("\n");
	}
	return 0;
}
