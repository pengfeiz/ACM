#include <iostream>
using namespace std;
#define MAX 1001

int a[MAX][MAX];
int n;

int main()
{
	bool f;
	int i,j;
	while(scanf("%d",&n))
	{
		f=true;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(i=0;f&&i<n-1;i++)
			for(j=0;f&&j<n-1;j++)
				if(a[i][j]+a[i+1][j+1]!=a[i][j+1]+a[i+1][j])
					f=false;
		if(!f)
			printf("not ");
		printf("homogeneous\n");
	}
	return 0;
}