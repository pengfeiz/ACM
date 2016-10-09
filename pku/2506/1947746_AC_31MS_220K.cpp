#include <iostream>
using namespace std;
int main()
{
	int num[251][100],i,j;
	for(i=0;i<251;i++)
		for(j=0;j<100;j++)
			num[i][j]=0;
	num[0][1]=num[1][1]=1;
	num[0][0]=num[1][0]=num[2][0]=2;
	num[2][1]=3;
	for(i=3;i<251;i++)
	{
		for(j=1;j<=num[i-2][0];j++)
			num[i][j]+=num[i-2][j]*2;
		for(j=1;j<=num[i-1][0];j++)
			num[i][j]+=num[i-1][j];
		for(j=1;j<=num[i-1][0];j++)
		{
			num[i][j+1]+=num[i][j]/10;
			num[i][j]%=10;
		}
		if(num[i][num[i-1][0]]!=0)
			num[i][0]=num[i-1][0]+1;
		else
			num[i][0]=num[i-1][0];
	}
	while(cin>>i)
	{
		for(j=num[i][0]-1;j>0;j--)
			cout<<num[i][j];
		cout<<endl;
	}
	return 0;
}
