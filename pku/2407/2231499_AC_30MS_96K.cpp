#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100000

int a[30][2],m,b[MAX],k,t;

bool prime(int x)
{
	int i,q=(int)sqrt(x*1.0);
	for(i=2;i<=q;i++)
		if(!(x%i))
			return false;
	return true;
}

void ouler(int n)
{
	int i;
	m=10;
	memset(a,0,sizeof(a));
	for(i=0;n!=1&&i<k&&b[i]<=n;i++)
	{
		if(n%b[i]==0)
			a[m++][0]=b[i];
		while(!(n%b[i]))
		{
			a[m-1][1]++;
			n/=b[i];
		}
	}
	if(n!=1)
	{
		a[m][0]=n;
		a[m++][1]=1;
	}
	t=1;
	for(i=0;i<m;i++)
	{
		if(a[i][1]>1)
			t*=(int)(pow(a[i][0],a[i][1]*1.0)-pow(a[i][0],(a[i][1]-1)*1.0));
		else
			t*=a[i][0]-1;
	}
	printf("%d\n",t);
}

int main()
{
	int n,i;
	for(i=2;i<=sqrt(1000000000);i++)
		if(prime(i))
			b[k++]=i;
	while(scanf("%d",&n),n)
		ouler(n);
	return 0;
}