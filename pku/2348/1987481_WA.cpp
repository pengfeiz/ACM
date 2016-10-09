#include <iostream>
using namespace std;
int main()
{
	__int64 a,b,t,p;
	while(scanf("%I64d%I64d",&a,&b)&&(a||b))
	{
		p=t=0;
		if(a<b)
			swap(a,b);
		while(a>b)
		{
			if(a/b>1)
			{
				t=1;
				break;
			}
			a=a%b;
			swap(a,b);
			p++;
		}
		if(t==0)
		{
			if(p%2==0)
				printf("Ollie wins\n");
			else
				printf("Stan wins\n");
		}
		else
		{
			if(p%2==1)
				printf("Ollie wins\n");
			else
				printf("Stan wins\n");
		}
	}
	return 0;
}		
