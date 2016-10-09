#include <iostream>
using namespace std;
#define MAX 10000
int main()
{
	int n,i,tt,j,num[MAX];
	while(cin>>n)
	{
		if(n<=4)
		{
			cout<<n<<endl;
			continue;
		}
		tt=0;
		num[0]=num[1]=0;
		for(i=2;tt<n;i++)
		{
			tt+=i;
			num[i]=1;
		}
		i--;
		j=tt-n;
		if(j!=1)
			num[j]=0;
		else
		{
			num[2]=0;
			num[i]=0;
			i++;
			num[i]=1;
		}
		for(j=0;j<i;j++)
			if(num[j]!=0)
				cout<<j<<" ";
		cout<<i<<endl;
	}
	return 0;
}