#include <iostream>
using namespace std;
int main()
{
	int i,q[100],n,t=0;
	cin>>n;
	if(n>1)
	{
		for(i=0;i<n;i++)
			cin>>q[i];
		for(i=0;i<n-1;i++)
			t+=abs(q[i+1]-q[i]);
	}
	cout<<t<<endl;
	return 0;
}