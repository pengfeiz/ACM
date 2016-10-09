#include <stdio.h>
int main()
{
	int a[100001],n,i;
	while(scanf("%d",&n)&&n!=0)
	{
		a[0]=0;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=n;i>0;i--)
			if(a[a[i]]!=i)
				break;
		if(i!=0)
			printf("not ambiguous\n");
		else
			printf("ambiguous\n");
	}
	return 0;
}

