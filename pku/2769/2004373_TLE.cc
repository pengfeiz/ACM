#include <iostream>
using namespace std;
#define MAX 1000000
#define MIN 300
int a[MAX],b[MIN];
int main()
{
	int n,i,t,q,nn;
	scanf("%d",&nn);
	while(nn-->0)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		t=n-1;
		q=0;
		while(q==0)
		{
			t++;
			q=1;
			memset(a,0,sizeof(a));
			for(i=0;i<n;i++)
			{
				if(a[b[i]%t]==0)
					a[b[i]%t]=1;
				else
				{
					q=0;
					break;
				}
			}
		}
		printf("%d\n",t);
	}
	return 0;
}

