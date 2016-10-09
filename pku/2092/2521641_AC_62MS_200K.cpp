#include <iostream>
using namespace std;
#define MAX 10001

int a[MAX];
int n,m;

int main()
{
	int i,j,p1,p2;
	while(scanf("%d%d",&n,&m),n||m)
	{
		memset(a,0,sizeof(a));
		n*=m;
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			a[j]++;
		}
		p1=p2=0;
		for(i=0;i<MAX;i++)
		{
			if(a[i]>a[p1])
			{
				p2=p1;
				p1=i;
			}
			else if(a[i]>a[p2])
			{
				p2=i;
			}
		}
		for(i=0;i<MAX;i++)
			if(a[i]==a[p2])
			{
				if(i-p2)
					printf(" ");
				printf("%d",i);
			}
		printf("\n");
	}
	return 0;
}