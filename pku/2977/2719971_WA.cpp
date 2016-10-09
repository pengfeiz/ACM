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
			l=ll(b+x)+ll(c);
			l=minn(l,ll(c+x)+ll(b));
			l=minn(l,ll(a+b-y)+ll(b+z));
			l=minn(l,ll(a+c-z)+ll(c+y));
		}
		else if(b==y)
		{
			l=ll(a+y)+ll(b);
			l=minn(l,ll(b+y)+ll(a));
			l=minn(l,ll(b+a-x)+ll(a+z));
			l=minn(l,ll(b+c-y)+ll(c+x));
		}
		else if(c==z)
		{
			l=ll(a+z)+ll(b);
			l=minn(l,ll(b+z)+ll(a));
			l=minn(l,ll(c+b-y)+ll(b+x));
			l=minn(l,ll(c+a-x)+ll(a+y));
		}
		printf("%d\n",l);
	}
	return 0;
}
