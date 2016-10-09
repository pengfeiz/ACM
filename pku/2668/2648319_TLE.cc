#include<stdio.h>
__int64 n,m;
__int64 ans;
int main()
{
	__int64 i,j,k;
	while(scanf("%I64d%I64d",&n,&m),n||m)
	{
		ans=0;
		i=n;
		while(i)
		{
			k=m/i;
			j=n/(k+1);
			ans+=k*(i-j);
			if(i==j)
				i--;
			else 
				i=j;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}