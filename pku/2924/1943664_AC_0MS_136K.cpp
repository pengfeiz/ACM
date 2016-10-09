#include <iostream>
using namespace std;
int main()
{
	__int64 n,m,k;
	int nn,i;
	cin>>nn;
	for(i=1;i<=nn;i++)
	{
		if(i-1)
			cout<<endl;
		cout<<"Scenario #"<<i<<":\n";
		scanf("%I64d%I64d",&n,&m);
		k=(m+n)*(m-n+1)/2;
		printf("%I64d\n",k);
	}
	return 0;
}

