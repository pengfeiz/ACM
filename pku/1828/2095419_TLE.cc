#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 50000
struct gao
{
	int x,y;
}a[MAX];

bool com(gao a,gao b)
{
	if(a.x<b.x)
		return true;
	if(a.x>b.x)
		return false;
	if(a.y<b.y)
		return true;
	return false;
}

int main()
{
	int n,i,j,t;
	while(scanf("%d",&n)&&n)
	{
		t=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,com);
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>i;j--)
				if(a[i].x<=a[j].x&&a[i].y<=a[j].y)
					break;
			if(j==i)
				t++;
		}
		printf("%d\n",t);
	}
	return 0;
}
