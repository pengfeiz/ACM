#include <iostream>
using namespace std;
#define MAX 512
int a[MAX][MAX],n,m;


void build(int x,int size)
{
	int i,j;
	if(x==n)
		return;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			a[i][j+size]=a[i+size][j]=a[i][j]+(1<<x);
			a[i+size][j+size]=a[i][j];
		}
		a[i][i+size]--;
	}
	build(x+1,size<<1);
}


int main()
{
	int i,j;
	a[0][0]=1;
	scanf("%d",&n);
	n++;
	m=1<<(n-1);
	build(1,1);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(j)
				printf(" ");
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}