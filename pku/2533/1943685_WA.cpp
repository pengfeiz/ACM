#include <iostream>
using namespace std;
int main()
{
	int a[1000],n,i,b[1000],j,max;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=1;
	}
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			max=1;
			if(a[i]<a[j]&&b[i]+1>max)
			{
				b[j]=b[i]+1;
				max=b[j];
			}
		}
	max=0;
	for(i=0;i<n;i++)
		if(b[i]>max)
			max=b[i];
	cout<<max<<endl;
	return 0;
}
