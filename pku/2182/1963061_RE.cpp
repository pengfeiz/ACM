#include <iostream>
using namespace std;
#define MAX 8000
int main()
{
	int a[MAX],b[MAX],i,n,t,j,c[MAX],m=0;
	cin>>n;
    for(i=1;i<=n-1;i++)
        cin>>b[i];
    for(i=1;i<=(n-1)/2;i++)
	{
		t=b[i];
        b[i]=b[n-i];
        b[n-i]=t;
	}
    for(i=1;i<=n;i++)
		a[i]=i;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<b[i]+1;j++);
		{
			c[m]=a[j];
			m++;
		}
		for(;j<=n;j++)
			a[j]=a[j+1];
	}
	for(m=n-1;m>=0;m--)
		cout<<c[m]<<endl;
	return 0;
}
