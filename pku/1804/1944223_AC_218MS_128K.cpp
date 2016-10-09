#include <iostream>
using namespace std;
int main()
{
	long a[1000],i,j,n,nn,k,tt;
	cin>>nn;
	for(k=1;k<=nn;k++)
	{
		tt=0;
		if(k-1)
			cout<<endl;
		cout<<"Scenario #"<<k<<":\n";
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(a[i]>a[j])
					tt++;
		cout<<tt<<endl;
	}
	return 0;
}


