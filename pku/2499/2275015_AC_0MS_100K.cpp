#include <iostream>
using namespace std;

int l,r,a,b;

void dosth()
{
	if(a==b&&b==1)
		return;
	if(a==1)
	{
		r+=b-1;
		b=1;
		dosth();
		return;
	}
	if(b==1)
	{
		l+=a-1;
		a=1;
		dosth();
		return;
	}
	if(a>b)
	{
		l+=a/b;
		a%=b;
		dosth();
		return;
	}
	if(a<b)
	{
		r+=b/a;
		b%=a;
		dosth();
		return;
	}
	if(a==b)
	{
		l++;
		a--;
		dosth();
	}
}
		
int main()
{
	int n,tim=0;
	scanf("%d",&n);
	while(n--)
	{
		tim++;
		printf("Scenario #%d:\n",tim);
		scanf("%d%d",&a,&b);
		l=r=0;
		dosth();
		printf("%d %d\n\n",l,r);
	}
	return 0;
}

