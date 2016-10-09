#include <iostream>
using namespace std;
#define MAX 7


int a[MAX][MAX],n;
int min;


void dosth(int b[MAX],int x)
{
	int i,t=0,c[MAX],j;
	if(x==n)
	{
		for(i=0;i<n;i++)
			if(t<b[i])
				t=b[i];
		if(t<min)
			min=t;
		return;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			c[j]=b[(j+i)%n]+a[x][j];
		dosth(c,x+1);
	}
}


int main()
{
	int i,j;
	int b[MAX];
	while(scanf("%d",&n),n!=-1)
	{
		min=99999999;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<n;i++)
			b[i]=a[0][i];
		dosth(b,1);
		printf("%d\n",min);
	}
	return 0;
}