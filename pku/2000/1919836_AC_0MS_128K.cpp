#include <iostream>
using namespace std;
int main()
{
	int n,i,m,s;
	while(cin>>n&&n!=0)
	{
		m=0;
		for(i=1;m<=n;i++)
			m+=i;
		i--;
		m-=i;
		s=i*(n-m);
		m=i;
		for(i=1;i<m;i++)
			s+=i*i;
		cout<<n<<" "<<s<<endl;
	}
	return 0;
}

