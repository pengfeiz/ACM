#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 100001

int a[maxn];
int b[maxn];

int n,p;

int main()
{
int mmm;
scanf("%d",&mmm);
//	freopen("t1.in","r",stdin);
	int i,j,x;
while(mmm--){
	x=99999999;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&p);
	b[0]=0;
	for(i=1;i<=n;i++)
		b[i]=a[i-1]+b[i-1];
	b[n+1]=0;
	for(i=0;i<=n;i++)
	{
		if(b[n]-b[i]>=p)
		{
			j=lower_bound(b+i,b+n+1,b[i]+p)-b;
			if(j-i<x)
				x=j-i;
		}
	}
	printf("%d\n",x-1);}
	return 0;
}