#include <stdio.h>
#include <string.h>
#define MAX 1000000
#define MIN 300
bool a[MAX];
int b[MIN];
int main()
{
	int n,i,t,nn;
	scanf("%d",&nn);
	while(nn-->0)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		t=n-1;
		while(1)
		{
			t++;
			memset(a,0,sizeof(a));
			for(i=0;i<n;i++)
			{
				if(a[b[i]%t])
					break;
				else
			  	    a[b[i]%t]=true;
			}
			if(i==n)
				break;
		}
		printf("%d\n",t);
	}
	return 0;
}

