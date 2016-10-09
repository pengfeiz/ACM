#include <iostream>
using namespace std;

int ll(int x)
{return x*x;}
int minn(int a,int b)
{return a<b?a:b;}

int main()
{
	int x,y,z,a,b,c,l;
	while(scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c)&&x||y||z||a||b||c)
	{
		if(a==0)
			l=b*b+c*c;
		else if(b==0)
			l=a*a+c*c;
		else if(c==0)
			l=a*a+b*b;
		else if(a==x)
			l=minn(ll(b+y)+ll(c),ll(c+z)+ll(b));
		else if(b==y)
			l=minn(ll(a+x)+ll(c),ll(c+z)+ll(a));
		else if(c==z)
			l=minn(ll(a+x)+ll(b),ll(b+y)+ll(a));
		printf("%d\n",l);
	}
	return 0;
}
