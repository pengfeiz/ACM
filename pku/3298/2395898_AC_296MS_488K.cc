#include <iostream>
using namespace std;
#define MAX 30001

int a[MAX][2],n,b[MAX];

int maxx(int a,int b)
{return a>b?a:b;}

int main()
{
	int i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		memset(a,0,sizeof(a));
		b[0]=-999999;
		for(i=1;i<=n;i++)
		{
			if(b[i]>b[i-1])
				a[i][0]=a[i-1][1]+1;
			else
				a[i][0]=a[i-1][0];
			if(b[i]<b[i-1])
				a[i][1]=a[i-1][0]+1;
			else
				a[i][1]=a[i-1][1];
		}
		printf("%d\n",maxx(a[n][0],a[n][1]));
	}
	return 0;
}

		

