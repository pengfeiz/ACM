#include <iostream>
using namespace std;

long max(long a,long b)
{
	if(a>=b)
		return a;
	return b;
}

int main()
{
	long num[400][400],n,i,j,p;
	cin>>n;
	for(i=0;i<400;i++)
		for(j=0;j<400;j++)
			num[i][j]=0;
	p=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			cin>>p;
			num[i][j]=max(num[i-1][j-1]+p,num[i-1][j]+p);
		}
	}
	p=0;
	for(i=1;i<=n;i++)
		if(num[n][i]>p)
			p=num[n][i];
	cout<<p<<endl;
	return 0;
}
			
			