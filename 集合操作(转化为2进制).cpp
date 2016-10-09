#include <iostream>
using namespace std;


int a[10];
int c[10];

int main()
{
	int i,n,m;
	
	n=10;
	for(i=0;i<n;i++)
	{	c[i]=1<<i;
        printf("%5d",c[i]);
    } 
    printf("\n");
	while(scanf("%d",&m),m!=-1)
	{

		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
			if(m&c[i])
				a[i]=1;
		for(i=0;i<10;i++)
			printf("%d ",a[i]);
		printf("\n\n");
	}
	return 0;
}
