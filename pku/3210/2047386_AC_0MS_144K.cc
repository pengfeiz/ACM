#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int i,n,j;
	while(scanf("%d",&n)&&n)
	{
		for(j=n/2;j<=n;j++)
		{
			if(j%2==1)
				continue;
			for(i=0;i<n;i++)
				if(!((j>=i&&(j-i)%2==0)||(j>=n-i&&(j-n+i)%2==0)))
					break;
			if(i==n)
				break;
		}
		if(j>n)
			printf("No Solution!\n");
		else
			printf("%d\n",j);
	}
	return 0;
}


