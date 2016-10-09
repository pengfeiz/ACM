#include<iostream>
using namespace std;
#define MAX 1000

int a[MAX],n,t,b[MAX];

bool judge()
{
	int i;
	for(i=1;i<n;i++)
		if(a[i]!=a[i-1])
			return true;
	return false;
}

void dosth()
{
	int i;
	memset(a,0,sizeof(a));
	t=0;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(judge())
	{
		t++;
		for(i=0;i<n;i++)
			b[(i+1)%n]=a[(i+1)%n]/2+a[i]/2;
		for(i=0;i<n;i++)
			if(b[i]%2==1)
				b[i]++;
		memcpy(a,b,n*sizeof(int));
	}
	printf("%d %d\n",t,a[0]);
}

int main()
{
	while(scanf("%d",&n),n)
		dosth();
	return 0;
}
	