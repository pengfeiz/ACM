#include <iostream>
#include <math.h>
using namespace std;
float a[10000000];
int main()
{
	int o,i,n;
	cin>>o;
	a[0]=1;
	for(i=1;i<10000000;i++)
		a[i]=(float)log10((i+1)*1.0)+a[i-1];
	while(o-->0)
	{
		cin>>n;
		cout<<(int)a[n-1]<<endl;
	}
	return 0;
}



		
