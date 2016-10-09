#include<iostream>
using namespace std;
__int64 n,m,ans;
__int64 divv(int x,int y)
{
	if(!y)return INT_MAX;
	return x%y?x/y+1:x/y;
}
int main()
{
	__int64 i,j,k;
	while(scanf("%I64d%I64d",&n,&m),n||m)
	{
		ans=0;
		i=1;
		while(i<=m)
		{
			k=divv(n,i);
			j=divv(n,k-1);
			if(j>m)
				j=m+1;
			ans+=k*(j-i);
			i=j;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}