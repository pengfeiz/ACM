#include <iostream>
using namespace std;

__int64 n,x;

__int64 modd(__int64 y)
{
	if(y==0)
		return 1;
	if(y==1)
		return x%n;
	__int64 num;
	num=modd(y/2);
	num=(num*num)%n;
	if(y%2)
		num=(num*x)%n;
	return num%n;
}

void dosth()
{
	__int64 t=0,time,y,i;
	scanf("%I64d%I64d",&n,&time);
	for(i=0;i<time;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		t+=modd(y);
		t=t%n;
	}
	printf("%I64d\n",t);
}

int main()
{
	int z;
	scanf("%d",&z);
	while(z--)
		dosth();
	return 0;
}
