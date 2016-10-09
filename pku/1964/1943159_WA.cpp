#include <iostream>
using namespace std;
#define MAX 1001
int main()
{
	long a[MAX][MAX],nn,i,j,n,m,hehe[MAX],tt,mm,k;
	char c;
	cin>>nn;
	while(nn-->0)
	{
		tt=mm=0;
		scanf("%ld %ld",&n,&m);
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++)
			{
				if(i!=0&&j!=0)
				{
					scanf("%c",&c);
					if(c=='R')
						a[i][j]=0;
					else if(c=='F')
						a[i][j]=1;
					else
						j--;
				}
				else a[i][j]=0;
			}
		for(j=0;j<=m;j++)
			hehe[j]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]==1)
					hehe[j]++;
				else
					hehe[j]=0;
			}
			for(j=1;j<=m;j++)
			{
				if(hehe[j]==0||hehe[j]*(m-j+1)<=mm)
					continue;
				tt=1;
				k=j+1;
				if(k<=m)
				{
					while(hehe[k]>=hehe[j])
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
		cout<<mm*3<<endl;
	}
	return 0;
}