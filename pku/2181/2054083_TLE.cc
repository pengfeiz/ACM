#include <iostream>
using namespace std;
int a[150000];
int main()
{
	int n,i,j=0,max=0;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			if(a[i]>a[i+1]&&j==0)
			{
				max+=a[i];
				j++;
			}
			else if(a[i]<a[i+1]&&j==1)
			{
				max-=a[i];
				j--;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}