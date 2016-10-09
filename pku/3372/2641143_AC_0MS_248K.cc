#include <iostream>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		while(n>1)
		{
			if(n%2)
				break;
			n/=2;
		}
		if(n>1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
