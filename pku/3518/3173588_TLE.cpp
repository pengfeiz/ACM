#include <iostream>
#include <algorithm>
using namespace std;

const int manx=1400000;
int c[121000];
int m;


bool judge(int x)
{
	int i;
	for(i=0;i<m;i++)
		if(x%c[i]==0)
			return false;
	return true;
}


int main()
{

	int i,x;
	m=2;
	c[0]=2;
	c[1]=3;
	for(i=5;i<manx;i++)
		if(judge(i))
			c[m++]=i;

	while(scanf("%d",&x),x)
	{
		i=lower_bound(c,c+m,x)-c;
		if(c[i]==x)
			printf("0\n");
		else
			printf("%d\n",c[i]-c[i-1]);
	}


	return 0;
}
