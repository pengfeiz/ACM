#include <iostream>
using namespace std;

int main()
{
	int n,m,t,c;
	while(scanf("%d%d%d",&n,&m,&c),n||m||c)
	{
		if(c==0)
			t=(m-7)*(n-7)-(((m-6)/2)*((n-6)/2)+((m-7)/2)*((n-7)/2));
		else
			t=((m-6)/2)*((n-6)/2)+((m-7)/2)*((n-7)/2);
		printf("%d\n",t);
	}
	return 0;
}
