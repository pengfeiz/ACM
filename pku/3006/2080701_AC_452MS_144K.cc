#include <iostream>
#include <math.h>
using namespace std;
bool prime(int x)
{
	if(x==1)
		return true;
	int i;
	for(i=2;i<=sqrt(x);i++)
		if(!(x%i))
			return true;
	return false;
}
int main()
{
	int n,p,q;
	while(scanf("%d%d%d",&n,&p,&q)&&(n||p||q))
	{
		while(q-->0)
		{
			while(prime(n))
				n+=p;
			n+=p;
		}
		printf("%d\n",n-p);
	}			
	return 0;
}
