#include <iostream>
using namespace std;
int main()
{
	__int64 a,b,t;
	while(scanf("%I64d%I64d",&a,&b)&&(a||b))
	{
		t=0;
		while(1)
		{
			if(t==0)
			{
				if(a>=b)
					a=a%b;
				else
					b=b%a;
				t=1;
			}
			else
			{
				if(b>=a)
					b=b%a;
				else
					a=a%b;
				t=0;
			}
			if(a==0)
				break;
			else if(b==0)
				break;
		}
		if(t==0)
			cout<<"Ollie wins\n";
		else
			cout<<"Stan wins\n";
	}
	return 0;
}
		