#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000001
__int64 a[MAX];
int b[1000],m;

bool prime(int x)
{
	int i;
	for(i=2;i<=sqrt(x*1.0);i++)
		if(!(x%i))
			return false;
	return true;
}

int main()
{
	memset(a,0,sizeof(a));
	int n,i,j;
	m=0;
	for(i=2;i<=1000;i++)
		if(prime(i))
			b[m++]=i;
	for(i=2;i<MAX;i++)
	{
		for(j=0;j<m;j++)
			if(i%b[j]==0)
				break;
		if(j==m||(i/b[j])==1)
			a[i]=a[i-1]+i-1;
		else if((i/b[j])%b[j]==0)
			a[i]=a[i-1]+b[j]*(a[i/b[j]]-a[i/b[j]-1]);
		else
			a[i]=a[i-1]+(a[i/b[j]]-a[i/b[j]-1])*(a[b[j]]-a[b[j]-1]);
	}
	while(scanf("%d",&n),n)
		printf("%I64d\n",a[n]);
	return 0;
}