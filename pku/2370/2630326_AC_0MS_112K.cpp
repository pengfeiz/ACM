#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[102],i;
	int n,m,s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++ )
		scanf("%d",&a[i]);
	sort(a,a+n);
	m=(n+1)/2;
	for(i=0;i<m;i++)
		s+=(a[i]+1)/2;
	printf("%d\n",s);
	return 0;
}
