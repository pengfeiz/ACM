#include <stdio.h>
int n,i,j,a[260],k[10]={0,1},c[260],temp,count,mid;
int main()
{
	for(i=2;i<=9;i++)
		k[i]=2*k[i-1];
	while(scanf("%d",&n)!=EOF)
	{
        if (n==0) break;
		if(n==1)
		{scanf("%d",&a[1]);printf("%d\n",a[1]);continue;}
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		temp=1;
		while((mid=k[temp])<n)
		{
			count=1;
			for(i=1;i<=mid;i++)
			{c[count++]=(a[i]+a[i+mid])/2;	c[count++]=(a[i]-a[i+mid])/2;}
			for(i=1;i<=2*mid;i++)
				a[i]=c[i];
			temp++;
		}
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
