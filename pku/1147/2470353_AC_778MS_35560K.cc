#include <iostream>
using namespace std;
#define MAX 3001

int a[MAX][MAX];
int b[MAX];
int c[MAX];
int n;

int main()
{
	int i,t=0,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]==0)
			t++;
	}
	for(i=0;i<n;i++)
	{
		if(i<t)
			a[i][0]=0;
		else
			a[i][0]=1;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][0]==b[j])
			{
				c[j]=i;
				b[j]=-1;
				break;
			}
	for(i=1;i<n;i++)
		for(j=0;j<n;j++)
			a[c[j]][i]=a[j][i-1];
	for(i=0;i<n;i++)
	{
		if(i)
			printf(" ");
		printf("%d",a[0][i]);
	}
	printf("\n");
	return 0;
}



