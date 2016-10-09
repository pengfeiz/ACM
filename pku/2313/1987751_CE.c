#include <iostream>
using namespace std;
int main()
{
	int i,q[100],n,t=0,j;
	cin>>n;
	if(n>1)
	{
		for(i=0;i<n;i++)
			cin>>q[i];
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(q[i]>q[j])
					swap(q[i],q[j]);
		for(i=0;i<n-1;i++)
			t+=q[i+1]-q[i];
	}
	cout<<t<<endl;
	return 0;
}