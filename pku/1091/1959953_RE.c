#include <stdio.h>
#include <math.h>
__int64 a[1229];
int b[1229];
int prime(__int64 x)
{
	__int64 i;
	for(i=0;a[i]<=(__int64)sqrt((double)x);i++)
		if(x%a[i]==0)
			return 0;
	return 1;
}
int main()
{
	__int64 n,m,i,j,t,k;
	a[0]=2;
	for(i=3,j=1;i<10000;i++)
		if(prime(i))
			a[j++]=i;
	for(i=0;i<1229;i++)
		b[i]=0;
	scanf("%I64d%I64d",&n,&m);
	k=m;
	for(i=0;a[i]<=m&&i<1229;i++)
		if(m%a[i]==0)
		{
			b[i]=1;			
			while(k%a[i]==0)
				k/=a[i];
		}
	if(prime(k)==0)
		k=1;
	k=m/k;
	for(i=0,t=1;a[i]<=(__int64)sqrt(m*1.0);i++)
		if(b[i]==1)
		{
			k/=a[i];
			t*=(__int64)pow(a[i]*1.0,n*1.0)-1;
		}
	t*=(__int64)pow(k*1.0,n*1.0);
	printf("%I64d\n",t);
	return 0;
}


