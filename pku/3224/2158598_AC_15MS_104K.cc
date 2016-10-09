#include <stdio.h>
main()
{
	int i,j,n,m,t,a[105][105],max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
	{
		t=0;
		for(j=0;j<n;j++)
			if(a[i][j]>a[j][i])
				t++;
		if(t>max)
		{
			max=t;
			m=i;
		}
	}
	printf("%d\n",m+1);
}
