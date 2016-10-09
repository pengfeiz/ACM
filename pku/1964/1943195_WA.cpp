#include <iostream>
using namespace std;
#define MAX 1000
int main()
{
	long a[MAX],nn,i,j,n,m,hehe[MAX],tt,mm,k;
	char c;
	cin>>nn;
	while(nn-->0)
	{
		tt=mm=0;
		scanf("%ld %ld",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%c",&c);
				if(c=='R')
					a[j]=0;
				else if(c=='F')
					a[j]=1;
				else
					j--;
			}
			for(j=0;j<m;j++)
			{
				hehe[j]=0;
				for(j=0;j<m;j++)
				{
					if(a[j]==1)
						hehe[j]++;
					else
						hehe[j]=0;
				}
				for(j=0;j<m;j++)
				{
					if(hehe[j]==0||hehe[j]*(m-j+1)<=mm)
						continue;
					tt=1;
					k=j+1;
					if(k<m)
					{
						while(hehe[k]>=hehe[j]&&k<m)
						{
							tt++;
							k++;
						}
					}
					tt*=hehe[j];
					if(tt>mm)
						mm=tt;
				}
			}
		}
		cout<<mm*3<<endl;
	}
	return 0;
}