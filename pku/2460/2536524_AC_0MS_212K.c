#include <stdio.h>

int x[200001];
int y[200001];
int main()
{
	int n,i,a,b,xi,yi;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d %d",&x[i],&y[i]);
		a=b=0;
		xi=x[n/2];
		yi=y[n/2];
		for(i=0;i<n;i++)
			if(x[i]>xi&&y[i]>yi || x[i]<xi&&y[i]<yi)
				a++;
			else if(x[i]>xi&&y[i]<yi || x[i]<xi&&y[i]>yi)
				b++;
		printf("%d %d\n",a,b);
	}
	return 0;
}
