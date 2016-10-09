#include <iostream>
using namespace std;
int main()
{
	int n,a,b,c;
	while(cin>>n)
	{
		if(n==0)
		{
			cin>>a;
			printf("YES\n");
		}
		else if(n==1)
		{
			cin>>a>>b;
			printf("YES\n");
		}
		else if(n==2)
		{
			cin>>a>>b>>c;
			if(b*b==4*a*c)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else
		{
			while(n-->0)
				cin>>a;
			printf("NO\n");
		}
	}
	return 0;
}