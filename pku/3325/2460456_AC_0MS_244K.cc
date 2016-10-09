#include <iostream>
using namespace std;


int main()
{
	int a,b,q,n,t,i;
	while(scanf("%d",&n),n)
	{
		t=0;
		a=-999999;
		b=999999;
		for(i=0;i<n;i++)
		{
			scanf("%d",&q);
			if(q>a)
				a=q;
			if(q<b)
				b=q;
			t+=q;
		}
		t-=a+b;
		printf("%d\n",t/(n-2));
	}
	return 0;
}