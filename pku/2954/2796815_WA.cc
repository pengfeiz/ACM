#include <iostream>
using namespace std;

int gcd(int x,int y)
{
	int a;
	while(y)
	{
		a=x%y;
		x=y;
		y=a;
	}
	return x;
}


int main()
{
	int a1,b1,a2,b2,a3,b3;
	int x1,x2,y1,y2,x3,y3;
	while(scanf("%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3)!=EOF)
	{
		x1=a2-a1;
		y1=b2-b1;
		x2=a3-a2;
		y2=b3-b2;
		x3=a1-a3;
		y3=b1-b3;
		printf("%d\n",(x1*y2-x2*y1+2-gcd(abs(x1),abs(y1))-gcd(abs(x2),abs(y2))-gcd(abs(x3),abs(y3))));
	}
	return 0;
}
