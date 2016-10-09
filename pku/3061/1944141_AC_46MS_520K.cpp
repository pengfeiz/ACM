#include <iostream>
using namespace std;
int main()
{
	long num[100000],n,m,i,j,nn,tt,min;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n>>m;
		min=n+1;
		tt=0;
		for(i=0;i<n;i++)
		    scanf("%ld",&num[i]);
		for(i=j=0;i<n;i++)
		{
			while(tt<m&&j<n)
			{
				tt+=num[j];
				j++;
			}
			if(j-i<min&&tt>=m)
				min=j-i;
			tt-=num[i];
		}
		if(min==n+1)
			cout<<0<<endl;
		else
			cout<<min<<endl;
	}
	return 0;
}
					


	
