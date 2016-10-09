#include <iostream>
using namespace std;

int main()
{
	int n,i,j;
	int a,b,c,d;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		
		printf("Problem set %d: ",i);
		printf("%d / %d, ",a,b);
		printf("base 7 digits %d through %d: ",c,d);
		
		a%=b;

		for(j=0;j<=d;j++)
		{
			if(j>=c)
				printf("%d",(a*7)/b);
			a=a*7%b;
		}
		printf("\n");

	}

	return 0;
}