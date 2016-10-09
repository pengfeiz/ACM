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
			l=minn(ll(b+1)+ll(c),ll(c+1)+ll(b));
		else if(b==y)
			l=minn(ll(a+1)+ll(c),ll(c+1)+ll(a));
		else if(c==y)
			l=minn(ll(a+1)+ll(b),ll(b+1)+ll(a));
		printf("%d\n",l);
	}
	return 0;
}
