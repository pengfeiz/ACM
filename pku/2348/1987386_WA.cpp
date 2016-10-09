#include <iostream>
using namespace std;
int main()
{
	__int64 a,b,t,p;
	while(scanf("%I64d%I64d",&a,&b)&&(a||b))
	{
		p=0;
		t=1;
		if(a<b)
			swap(a,b);
		while(a>b)
		{
			if(a/b>1)
			{
				t=p%2;
				break;
			}
			a=a%b;
			swap(a,b);
			p++;
		}
		if(t==1)
			printf("Ollie wins\n");
		else
			printf("Stan wins\n");
	}
	return 0;
}		
