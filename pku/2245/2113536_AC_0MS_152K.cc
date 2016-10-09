#include <iostream>
#include <algorithm>
using namespace std;

int a[13],b[6],n;

bool com(int a,int b)
{
	return a<b;
}

void dosth(int x,int y)
{
	int i;
	if(x==6)
	{
		for(i=0;i<6;i++)
		{
			if(i)
				printf(" ");
			printf("%d",b[i]);
		}
		printf("\n");
		return;
	}
	for(i=y;i<=n+x-6;i++)
	{
		b[x]=a[i];
		dosth(x+1,i+1);
	}
}

int main()
{
	int i;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n,com);
		dosth(0,0);
		printf("\n");
	}
	return 0;
}
	