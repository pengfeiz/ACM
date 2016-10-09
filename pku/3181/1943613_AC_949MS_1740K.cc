#include <iostream>
#include <math.h>
#include <stdio.h>
#define cc 16.0
using namespace std;
int main()
{
	__int64 a[1001][101][2],sum[2];
	int n,k,i,j,m;
	for(i=0;i<=1000;i++)
		for(j=0;j<=100;j++)
		{
			a[i][j][0]=0;
			a[i][j][1]=0;
		}
	for(i=1;i<=1000;i++)
		for(j=1;j<=100;j++)
		{
			if(i==j||j==1)
               	a[i][j][0]=1;
		    else if(i>j)
			{
				for(k=1;k<=j;k++)
				{
					a[i][j][0]+=a[i-j][k][0];
					a[i][j][1]+=a[i-j][k][1];
					if(a[i][j][0]>=(__int64)pow(10,cc))
					{
	                    a[i][j][1]+=1;
                   	    a[i][j][0]-=(__int64)pow(10,cc);
                    }
				}
			}
		}
	cin>>n>>m;
	sum[0]=sum[1]=0;
	for(i=1;i<=m;i++)
	{
		sum[0]+=a[n][i][0];
		sum[1]+=a[n][i][1];
		if(sum[0]>=(__int64)pow(10,cc))
		{
            sum[1]+=1;	
            sum[0]-=(__int64)pow(10,cc);
		}
	}
	if(sum[1]>0)
    {
       	printf("%I64d",sum[1]);
        j=1;	
    	while(sum[0]<(__int64)pow(10,cc-j))
    	{
            cout<<"0";
            j++;
        }
    }
	printf("%I64d\n",sum[0]);
	cin>>m;
	return 0;
}
