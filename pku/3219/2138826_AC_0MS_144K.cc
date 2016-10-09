#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,m,t1,t2,p;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		t1=t2=0;
		p=n-m;
		while(n>=2)
		{
			t1+=n/2;
			n/=2;
		}
		while(m>=2)
		{
			t2+=m/2;
			m/=2;
		}
		while(p>=2)
		{
			t2+=p/2;
			p/=2;
		}
		if(t1>t2)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}

