#include <iostream>
using namespace std;
int main()
{
	long n,i,m;
	while(cin>>n)
	{
		m=n;
		i=1;
		while(m>i)
		{
			m-=i;
			i++;
		}
		if(i%2==0)
			cout<<"TERM "<<n<<" IS "<<m<<"/"<<(i-m+1)<<endl;
		else cout<<"TERM "<<n<<" IS "<<(i-m+1)<<"/"<<m<<endl;
	}
	return 0;
}