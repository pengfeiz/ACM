#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a,b,xa,ya,xb,yb,i;
	scanf("%d%d",&a,&b);
	ya=yb=1;
	i=1;
	while(a>i)
	{
		a-=i;
		i+=2;
		ya++;
	}
	if(a%2)
		ya=ya*2-1;
	else
		ya=ya*2-2;
	xa=a-(i+1)/2;
	i=1;
	while(b>i)
	{
		b-=i;
		i+=2;
		yb++;
	}
	if(b%2)
		yb=yb*2-1;
	else
		yb=yb*2-2;
	xb=b-(i+1)/2;
	if(ya>yb)
	{
		swap(xa,xb);
		swap(ya,yb);
	}
	else if(ya==yb&&xa>xb)
	{
		swap(xa,xb);
		swap(ya,yb);
	}
	if(ya%2)
		i=(yb-ya)/2;
	else
		i=(yb-ya+1)/2;
	xa=abs(xa-xb);
	if(xa<=i)
		printf("%d\n",abs(ya-yb));
	else
		printf("%d\n",(xa-i)+abs(ya-yb));
	return 0;
}
