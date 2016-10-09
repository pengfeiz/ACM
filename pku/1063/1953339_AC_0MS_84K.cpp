#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int a[30],nn,n,i,t[2];
	cin>>nn;
	while(nn-->0)
	{
		cin>>n;
		for(i=t[0]=t[1]=0;i<n;i++)
			cin>>a[i];
		if(n%2==1)
		{
			cout<<"YES\n";
			continue;
		}
		for(i=0;i<n;i++)
			if(a[i]==0)
				t[i%2]++;
		if(abs(t[0]-t[1])<2)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
