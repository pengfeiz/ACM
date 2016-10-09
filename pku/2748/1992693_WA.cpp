#include <iostream>
using namespace std;
int a[75000];
int main()
{
	int q,t,i;
	q=1;
	a[0]=1;
	for(i=1;i<75000;i++)
	{
		a[i]=a[i-1]+q;
		q+=a[i];
	}
	cin>>t;
	while(t-->0)
	{
		scanf("%d",&q);
		printf("%d\n",a[q%75000-1]);
	}
	return 0;
}
