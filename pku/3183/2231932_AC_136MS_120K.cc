#include <iostream>
using namespace std;

int main()
{
	int n,p,q,x,i,t;
	scanf("%d",&n);
	p=q=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x>p)
		{
			if(q)
			{
				printf("%d\n",t);
				q=0;
			}
			p=x;
		}
		else if(x<p)
		{
			if(!q)
			{
				t=i;
				q=1;
			}
			p=x;
		}
		else
		{
			if(q)
				printf("%d\n",t);
			else
				printf("%d\n",i);
			q=0;
			p=x;
		}
	}
	if(q)
		printf("%d\n",t);
	else
		printf("%d\n",n);
	return 0;
}