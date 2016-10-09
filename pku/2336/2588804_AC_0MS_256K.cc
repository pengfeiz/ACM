#include <iostream>
using namespace std;


#define MAX 1500


int a[MAX];
int n,t,m;

bool judge(int x)
{
	int i;
	for(i=n;i>0;i-=m)
	{
		while(a[i]+t>x)
			return false;
		x-=2*t;
	}
	return true;
}

int main()
{
	int tt,i,l,r,mid;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d%d",&m,&t,&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		r=9999999;
		l=0;
		while(r>l)
		{
			mid=(r+l)/2;
			if(judge(mid))
				r=mid;
			else
				l=mid+1;
		}
		printf("%d %d\n",r,(n+m-1)/m);
	}
	return 0;
}