#include <iostream>
using namespace std;
long n[5];
int main()
{
	long nn,i;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n[0]>>n[1]>>n[2]>>n[3];
		for(i=0;i<4;i++)
			cout<<n[i]<<" ";
		if(n[0]+n[2]==2*n[1]&&n[1]+n[3]==2*n[2])
			cout<<2*n[3]-n[2]<<endl;
		else
			cout<<n[3]*n[3]/n[2]<<endl;
	}
	return 0;
}