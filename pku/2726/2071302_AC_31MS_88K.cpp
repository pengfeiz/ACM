#include <iostream>
using namespace std;
int a[10001];
int main()
{
	int n,i,p,q;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<10001;i++)
			a[i]=999999;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p,&q);
			if(q<a[p])
				a[p]=q;
		}
		for(p=q=0,i=1;i<10001;i++)
		{
			if(a[q]>a[i])
			{
				p++;
				q=i;
			}
		}
		printf("%d\n",p);
	}
	return 0;
}
