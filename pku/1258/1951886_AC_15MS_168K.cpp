#include <iostream>
using namespace std;
#define MAx 100
long a[100][100];
int b[100];
int main()
{
	int n,i,j;
	long tt,t,min,x;
	while(cin>>n)
	{
		tt=0;
		t=1;
		for(i=0;i<n;i++)
		{
			b[i]=0;
			for(j=0;j<n;j++)
				scanf("%ld",&a[i][j]);
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


				
		
