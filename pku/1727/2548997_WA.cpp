#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=100001;


struct gao
{
	int x,y,l;
}a[maxn];

int n,m;

bool com(gao a,gao b)
{return a.l<b.l;}


bool judge(int mid)
{
	int t=0,i,p=-99999999;
	for(i=0;i<n;i++)
	{
		if(abs(a[i].x-p)>a[i].y-mid)
		{
			t++;
			p=a[i].x+a[i].y-mid;
		}
		if(t>m)
			return true;
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int tt,ii,i;
	scanf("%d",&tt);
	int l,r,mid,minn;
	for(ii=1;ii<=tt;ii++)
	{
		scanf("%d%d",&n,&m);
		minn=9999999;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].y,&a[i].x);
			a[i].x+=1000000;
			a[i].y+=1000000;
			if(a[i].y<minn)
				minn=a[i].y;
			a[i].l=a[i].x+a[i].y;
		}
		sort(a,a+n,com);
		l=0;
		r=minn+1;
		while(r>l)
		{
			mid=(r+l)/2;
			if(judge(mid))
				r=mid;
			else
				l=mid+1;
		}
		printf("Case %d: %d\n",ii,r-1-1000000);
	}
	return 0;
}