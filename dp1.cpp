#include <iostream>
using namespace std;


int a[16];
int b[4]={1,2,5,10};


int main()
{
	int n,m,i,j,p;
	memset(a,0,sizeof(a));
	a[0]=1;
	n=16;
	m=4;
	for(i=0;i<m;i++)
	{
		for(j=b[i];j<n;j++)
			a[j]+=a[j-b[i]];
	}
	for(i=0;i<15;i++)
		printf("value:%d  %d\n",i,a[i]);
	printf("\n");
system("pause");	
 return 0;
}

