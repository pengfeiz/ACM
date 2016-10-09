#include <iostream>
using namespace std;
#define MAX 501

int a[MAX][MAX],b[MAX][MAX],p;
int n;

int main()
{
	int i,j,k;
	bool x;
	while(scanf("%d",&n)!=EOF)
	{
		x=true;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&b[i][j]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%I64d",&p);
				if(x)
				{
					for(k=0;k<n;k++)
						p-=a[i][k]*b[k][j];
					if(p)
						x=false;
				}
			}
		}
		if(x)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
