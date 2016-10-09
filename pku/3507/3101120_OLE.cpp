#include <iostream>
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
			printf("%d",n/6);
			n=n%6*10;
		}
		printf("\n");
	}
	return 0;
}
