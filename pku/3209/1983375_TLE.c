#include <stdio.h>
#include <math.h>
void main()
{
	__int64 n,t,i,o,p;
	scanf("%I64d",&o);
	while(o-->0)
	{
		scanf("%I64d",&n);
		if(n<0)  
		{
			printf("NO\n");
			continue;
		}
		for(i=2,p=0;i<=n&&p==0&&i<500000;i++)
		{
			t=0;
			while(n%i==0)
			{
				n/=i;
				t++;
			}
			if(i%4==3&&t%2==1)
				p=1;
		}			
		if(p||(i==500000&&n%4==3))
			printf("NO\n");
		else 
			printf("YES\n");
	}
}

			