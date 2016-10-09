#include <iostream>
using namespace std;
#define MAX 50002

int a[MAX],n,T;
int b[MAX],ans;

void find()
{
	int i,j,mid,k;
	for(k=1;k<=n;k++)
	{
		i=1;
		j=ans;
		while(i<=j)
		{
			mid=(i+j)/2;
			//>为最长递减子序列 >=非递增 <递增 <=非递减
			if(b[mid]>a[k])
				i=mid+1;
			else
				j=mid-1;
		}
		if(i>ans)
			ans++;
		b[i]=a[k];
	}
}

int main()
{
	int i,x,y;
	while(scanf("%d",&n),n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		ans=0;
		find();
		printf("%d\n",ans);
	}
	printf("*\n");
	return 0;
}