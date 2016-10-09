#include <iostream>
using namespace std;
int main()
{
	int num[20][20],i,j,n,m;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j>i)
				num[j][i]=0;
			else
			{
				num[j][i]=m;
				m++;
				if(m==10)
					m=1;
			}
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(j)
				cout<<" ";
			if(num[i][j]==0)
				cout<<" ";
			else
				cout<<num[i][j];			
			if(j==n-1)
				cout<<endl;
		}
	return 0;
}




