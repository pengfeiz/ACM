#include <iostream>
using namespace std;

int n,m;

bool dosth(int m)
{
	int t,p;
	t=n-1;
	p=(m-1)%t;
	while(t>1)
	{
		if(!p)
			return true;
		t--;
		p=(p+m-1)%t;
	}
	return false;
}

int main()
{
	while(scanf("%d",&n),n)
	{
		for(m=2;dosth(m);m++);
		printf("%d\n",m);
	}
	return 0;
}
