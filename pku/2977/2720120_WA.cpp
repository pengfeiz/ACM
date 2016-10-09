#include <iostream>
using namespace std;

int ll(int x)
{return x*x;}
int minn(int a,int b)
{return a<b?a:b;}

int main()
{
	int x,y,z,a,b,c,l;
	while(scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c),x||y||z||a||b||c)
	{
		if(a==0)
			l=b*b+c*c;
		else if(b==0)
			l=a*a+c*c;
		else if(c==0)
			l=a*a+b*b;
		else if(a==x)
		{
			l=ll(b+a)+ll(c);
			l=minn(l,ll(c+a)+ll(b));
			l=minn(l,ll(x+y-b)+ll(y+b));
			l=minn(l,ll(x+z-c)+ll(z+b));
		}
		else if(b==y)
		{
			l=ll(a+b)+ll(c);
			l=minn(l,ll(c+b)+ll(a));
			l=minn(l,ll(y+x-a)+ll(c+x));
			l=minn(l,ll(y+z-c)+ll(a+z));
		}
		else if(c==z)
		{
			l=ll(a+c)+ll(b);
			l=minn(l,ll(b+c)+ll(a));
			l=minn(l,ll(z+y-b)+ll(c+y));
			l=minn(l,ll(z+x-a)+ll(a+x));
		}
		printf("%d\n",l);
	}
	return 0;
}
