#include <iostream>
using namespace std;
int main()
{
	int num[302],nn,i,n,j,tt;
	cin>>nn;
	num[0]=0;
	for(i=1;i<302;i++)
		num[i]=(i+1)*i/2;
	for(i=1;i<=nn;i++)
	{
		tt=0;
		cout<<i<<" ";
		cin>>n;
		cout<<n<<" ";
		for(j=0;j<=n;j++)
			tt+=j*num[j+1];
		cout<<tt<<endl;
	}
	return 0;
}
		
