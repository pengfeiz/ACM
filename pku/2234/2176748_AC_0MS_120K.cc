#include <iostream>
using namespace std;
int main()
{
	int n,t,p;
	while(scanf("%d",&n)!=EOF)
	{
		t=0;
		while(n--)
		{
			scanf("%d",&p);
			t^=p;
		}
		if(t)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}