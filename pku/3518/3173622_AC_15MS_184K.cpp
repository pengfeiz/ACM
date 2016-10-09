#include <iostream>
#include <algorithm>
using namespace std;

const int manx=1400;
int c[1000];
int m;


bool judge(int x)
{
	int i;
	for(i=0;i<m&&c[i]<x;i++)
		if(x%c[i]==0)
			return false;
	return true;
}


int main()
{

	int i,x,p,q;
	m=2;
	c[0]=2;
	c[1]=3;
	for(i=5;i<manx;i++)
		if(judge(i))
			c[m++]=i;

	while(scanf("%d",&x),x)
	{
/*		i=lower_bound(c,c+m,x)-c;
		if(c[i]==x)
			printf("0\n");
		else
			printf("%d\n",c[i]-c[i-1]);*/
		if(judge(x))
			printf("0\n");
		else
		{
			p=q=x;
			while(!judge(p))
				p--;
			while(!judge(q))
				q++;
			printf("%d\n",q-p);
		}
	}


	return 0;
}
