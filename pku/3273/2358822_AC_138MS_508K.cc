#include <iostream>
using namespace std;

#define MAX 100002

int a[MAX],n,m,t;

bool dosth(int mid)
{
	int i,x=1,q=0;
	for(i=0;i<n;i++)
	{
		q+=a[i];
		if(mid<a[i])
			return false;
		if(q>mid)
		{
			q=a[i];
			x++;
		}
		if(x>m)
			return false;
	}
	return true;
}


int main()
{
	int i,p,q,mid;
	t=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		t+=a[i];
	}
	p=0;
	q=t;
	while(p<q)
	{
		mid=(p+q)/2;
		if(dosth(mid))
			q=mid;
		else
			p=mid+1;
	}
	printf("%d\n",q);
	return 0;
}
		
	

