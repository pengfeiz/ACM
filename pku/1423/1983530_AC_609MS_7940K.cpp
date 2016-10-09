#include <iostream>
#include <math.h>
using namespace std;
double a[1000001],f;
int main()
{
	int o,i,n,j;
	cin>>o;
	a[0]=1;
	for(i=1;i<1000001;i++)
	{
		a[i]=0;
		for(j=0;j<10;j++)
			a[i]+=(double)log10((j+i*10-9)*1.0);
		a[i]+=a[i-1];
	}
	while(o-->0)
	{
		cin>>n;
		f=a[n/10];
		i=n%10;
		n=n-n%10;
		for(j=1;j<=i;j++)
			f+=log10((n+j)*1.0);
		cout<<(int)f<<endl;
	}
	return 0;
}



		
