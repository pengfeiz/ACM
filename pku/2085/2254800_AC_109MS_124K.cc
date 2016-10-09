#include <iostream>
using namespace std;

#define MAX 50001;


int main()
{
	__int64 n,m,nn,i,j;
	while(scanf("%I64d%I64d",&n,&m),n!=-1&&m!=-1)
	{
		nn=n;
		i=1;
		while(m<=((n-1)*(n-2)/2)&&n>1)
		{
			printf("%I64d ",i);
			i++;
			n--;
		}
		m-=(n-1)*(n-2)/2;
		printf("%I64d",i+m);
		for(j=nn;j>=i;j--)
			if(j!=i+m)
				printf(" %I64d",j);
		printf("\n");
	}
	return 0;
}