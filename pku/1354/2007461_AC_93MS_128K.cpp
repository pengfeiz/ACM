#include <iostream>
using namespace std;
#define MAX 10
int a[10000];
void dosth(int n)
{
	int i,j;
	for(i=n;i>1;i--)
	{
		for(j=1;j<=a[0];j++)
			a[j]*=i;
		for(j=1;j<a[0];j++)
		{
			a[j+1]+=a[j]/MAX;
			a[j]%=MAX;
		}
		while(a[a[0]]>=MAX)
		{
			a[a[0]+1]=a[a[0]]/MAX;
			a[a[0]]%=MAX;
			a[0]++;
		}
	}
}	
int main()
{
	int n,i;
	while(scanf("%d",&n)&&n!=-1)
	{
		memset(a,0,sizeof(a));
		a[0]=1;
		a[1]=2;
		dosth(n-1);
		printf("N=%d:\n",n);
		for(i=a[0];i>0;i--)
			printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}