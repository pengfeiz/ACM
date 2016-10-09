#include <iostream>
using namespace std;
int main()
{
	int a[30],nn,n,i,j;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
		{
			if(a[i]==0)
				continue;
			j=i;
			while(a[j]==1&&j<n)
				j+=2;
			if(j<n)
			{
				a[j]=1;
				a[i]=0;
			}
		}
		for(i=1;i<n;i++)
			if(a[i]==0&&a[i-1]==1)
				break;
		if(i==n)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
