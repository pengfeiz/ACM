#include <iostream>
using namespace std;

__int64 s,d;

int main()
{
	while(scanf("%I64d%I64d",&s,&d)!=EOF)
	{
		if(4*s<d)
		{
			if(10*s<=2*d)
				printf("Deficit\n");
			else
				printf("%I64d\n",10*s-2*d);
		}
		else if(3*s<2*d)
		{
			if(8*s<=4*d)
				printf("Deficit\n");
			else
				printf("%I64d\n",8*s-4*d);
		}
		else if(2*s<3*d)
		{
			if(s<=d)
				printf("Deficit\n");
			else
				printf("%I64d\n",6*s-6*d);
		}
		else if(s<4*d)
		{
			if(3*s<=9*d)
				printf("Deficit\n");
			else
				printf("%I64d\n",3*s-9*d);
		}
		else
			printf("Deficit\n");
	}
	return 0;
}

