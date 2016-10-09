#include <iostream>
using namespace std;
#define MAX 101
int num[MAX][MAX];
int main()
{
	int n,i,j,sum,k,max;
	cin>>n;
	for(i=0;i<n;i++)
	{
		num[i][0]=0;
		num[0][i]=0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>sum;
			num[i][j]=num[i][j-1]+sum;
		}
	max=-10000;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			sum=0;
			for(k=1;k<=n;k++)
			{
				sum+=num[k][j]-num[k][i-1];
				if(sum<0)
					sum=0;
				if(sum>max)
					max=sum;
			}
		}
	cout<<max<<endl;
	return 0;
}
