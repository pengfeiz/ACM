#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];
int main()
{
	memset(a,0,sizeof(a));
	int i,j,n=0,m,t=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	i=0;
	j=n-1;
	while(i<=j)
	{
		if(a[i]+a[j]<=m)
		{
			i++;
			j--;
		}
		else
			j--;
		t++;
	}
	printf("%d\n",t);
	return 0;
}



