#include <iostream>
using namespace std;
#define MAx 100
long a[100][100];
int b[100];
int main()
{
	int n,i,j,m;
	long tt,t,min,x;
	while(cin>>n&&n)
	{
		cin>>m;
		tt=0;
		t=1;
		for(i=0;i<n;i++)
		{
			b[i]=0;
			for(j=0;j<n;j++)
				a[i][j]=99999;
		}
		for(i=0;i<m;i++)
		{
			cin>>x>>j>>min;
			if(min<a[x-1][j-1])
				a[x-1][j-1]=a[j-1][x-1]=min;
		}
		b[0]=1;
		while(t++<n)
		{
			min=99999;
			for(i=0;i<n;i++)
			{
				if(b[i]==1)
				{
					for(j=0;j<n;j++)
						if(b[j]==0&&a[i][j]<min)
						{
							x=j;
							min=a[i][j];
						}
				}
			}
			b[x]=1;
			tt+=min;
		}
		cout<<tt<<endl;
	}
	return 0;
}


				
		
