#include <iostream>
using namespace std;
int main()
{
	int a[16],i,j;
	a[0]=1;
	a[1]=3;
	for(i=2;i<16;i++)
	{
		a[i]=3*a[i-1];
		for(j=i-2;j>=0;j--)
			a[i]+=2*a[j];
	}
	while(cin>>i&&(i+1))
	{
		if(i%2==1)
			printf("0\n");
		else
			printf("%d\n",a[i/2]);
	}
	return 0;
}
