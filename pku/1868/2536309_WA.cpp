#include <iostream>
using namespace std;

#define MAX 10001

int a[MAX],n;

int main()
{
	int i,j,d;
	while(scanf("%d",&n),n)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%d",&d);
			a[d]=i;
		}
		for(i=1;i<=n/2;i++)
		{
			for(j=0;j+2*i<n;j+=i)
				if((a[j]<a[j+i])^(a[j+i]>a[j+2*i]))
					break;
			if(j+2*i<n)
				break;
		}
		if(i>n/2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}