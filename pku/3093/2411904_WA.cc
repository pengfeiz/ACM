#include <iostream>
#include <algorithm>
using namespace std;

unsigned int V,D,d[31],sum[31];
unsigned int dp[31][1001];


void work()
{
	int i,j;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=V;i++)
    {
	    for(j=1;j<=D;j++)
		{
		    if(j>=sum[i])
			    dp[i][j]=1;
		    else
			{
			    if(j>=d[i])
//				{
	//			    if(dp[i-1][j-d[i]]>0)
				        dp[i][j]=dp[i-1][j-d[i]]+dp[i-1][j];
	///			    else
	//		            dp[i][j]=1+dp[i-1][j];
    ///            }
			    else
				    dp[i][j]=dp[i-1][j];
		   }
	   }
   }
}

int main()
{
	int T,i,k; 
	scanf("%d",&T);
	for(k=1;k<=T;k++)
	{
	    scanf("%u%u",&V,&D);
		for(i=1;i<=V;i++)
			scanf("%u",&d[i]);
		sort(d+1,d+1+V);
        sum[0]=0;
		for(i=1;i<=V;i++)
			sum[i]=sum[i-1]+d[i];
        work();
		printf("%u %u\n",k,dp[V][D]);
	}
    return 0;
}
