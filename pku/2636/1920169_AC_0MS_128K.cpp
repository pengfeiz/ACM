#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,t,i,m;
	cin>>n;
	while(n-->0)
	{
		t=0;
		cin>>m;
		while(m-->0)
		{
			cin>>i;
			t+=i-1;
		}
		cout<<t+1<<endl;
	}
	return 0;
}
