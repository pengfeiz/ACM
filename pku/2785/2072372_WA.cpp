#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 4000
int a[MAX*MAX],b[MAX][4];

bool com(int a,int b)
{
	return a<b;
}

int main()
{
	int n,i,j,t;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<4;j++)
				scanf("%d",&b[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i*n+j]=b[i][2]+b[j][3];
		sort(a,a+n*n,com);
		t=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(binary_search(a,a+n*n,-(b[i][0]+b[j][1]),com))
					t++;
		printf("%d\n",t);
	}
	return 0;
}