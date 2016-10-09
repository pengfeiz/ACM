#include <iostream>
#include <algorithm>
using namespace std;
bool com(int &a,int &b)
{
	return (b-a)>0;
}
int main()
{
	int a[1024],nn,n,m,i;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<m;i++)
			next_permutation(a,a+n,com);
		for(i=0;i<n;i++)
		{
			if(i)
				cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}

