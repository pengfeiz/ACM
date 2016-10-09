#include <iostream>
using namespace std;
#define MAX 1000

int a[MAX];

int main()
{
	int j,n,m,i,t,h;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		a[0]=1;
		h=0;
		a[1]=1;
		for(j=n;j>1;j--)
		{
			for(i=1;i<=a[0];i++)
				a[i]*=j;
			for(i=1;i<a[0];i++)
			{
				a[i+1]+=a[i]/10;
				a[i]%=10;
			}
			while(a[a[0]]>9)
			{
				a[0]++;
				a[a[0]]=a[a[0]-1]/10;
				a[a[0]-1]%=10;
			}
		}
		for(i=1;i<=a[0];i++)
			if(a[i]==m)
				h++;
		printf("%d\n",h);
	}
	return 0;
}
