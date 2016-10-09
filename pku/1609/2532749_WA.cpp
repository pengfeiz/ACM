#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10002

struct gao
{
	int x,y;
}a[MAX],b[MAX];
int n,T;
int ans;

bool com(gao a,gao b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}

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
			if(b[mid].x<a[k].x&&b[mid].y<a[k].y)
				i=mid+1;
			else
				j=mid-1;
		}
		if(i>ans)
			ans++;
		b[i].x=a[k].x;
		b[i].y=a[k].y;
	}
}

int main()
{
	int i;
	while(scanf("%d",&n),n)
	{
		for(i=1;i<=n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,com);
		ans=0;
		find();
		printf("%d\n",ans);
	}
	printf("*\n");
	return 0;
}