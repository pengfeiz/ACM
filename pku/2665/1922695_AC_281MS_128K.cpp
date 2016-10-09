#include <iostream>
using namespace std;
int main()
{
	long n,k,m1,m2;
	while(cin>>n>>k&&(n||k))
	{
		n++;
		while(k-->0)
		{
			cin>>m1>>m2;
			n-=m2-m1+1;
		}
		cout<<n<<endl;
	}
	return 0;
}