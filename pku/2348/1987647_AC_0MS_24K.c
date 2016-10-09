#include <stdio.h>
void main()
{
	__int64 n,m,r,num;
	int k;
	while(scanf("%I64d %I64d",&n,&m)&&(m||n))
	{
		num=k=0;
		if(n<m)
		{
			__int64 temp=n;
			n=m;
			m=temp;
		}
		while(n>m)
		{
			if(n/m>1)
				break;
			n=n%m;
			r=m;
			m=n;
			n=r;
			num++;
		}
		if(num%2==0)
			printf("Stan wins\n");
		else 
			printf("Ollie wins\n");
	}
}
