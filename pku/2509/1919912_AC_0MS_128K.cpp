#include <iostream>
using namespace std;
int main()
{
	int n,m,q,p;
	while(cin>>n>>m)
	{
		q=p=n;
		while(p>=m)
		{
			p=n%m+n/m;
			q+=n/m;
			n=p;
		}
		cout<<q<<endl;
	}
	return 0;
}
