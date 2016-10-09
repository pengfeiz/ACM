#include <iostream>
using namespace std;
int main()
{
	long num[100000],n,m,i,j,nn,tt,min;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n>>m;
		min=n;
		for(i=0;i<n;i++)
			scanf("%ld",&num[i]);
		for(i=0;i<n;i++)
		{
			tt=0;
			for(j=i;j<i+min&&j<n;j++)
			{
				tt+=num[j];
				if(tt>=m&&j-i+1<min)
				{
					min=j-i+1;
					break;
				}
			}
		}
		cout<<min<<endl;
	}
	return 0;
}
					


	
