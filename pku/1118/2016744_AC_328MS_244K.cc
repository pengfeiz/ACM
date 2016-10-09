#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000
double a[MAX+1],b[MAX][2];
int main()
{
	long n,i,j,k,max;
	while(cin>>n&&n)
	{
		memset(a,0,n);
		max=2;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&b[i][0],&b[i][1]);
		for(i=0;i<n;i++)
		{
			for(k=0;k<n;k++)
			{
				if(i==k)
			    	a[k]=-98765432;
				else if(b[i][0]==b[k][0])
					a[k]=98765432;
				else
					a[k]=(b[i][1]-b[k][1])/(b[i][0]-b[k][0]);
			}
			sort(a,a+n);
			a[n]=-987654;
			j=2;
			for(k=1;k<=n;k++)
			{
				if(a[k]==a[k-1])
					j++;
				else
				{
					if(j>max)
						max=j;
					j=2;
				}
			}
			if(max>n/2)
				break;
		}				
		cout<<max<<endl;
	}
	return 0;
}