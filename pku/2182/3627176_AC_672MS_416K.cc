
#include<stdio.h>
int main()
{
	int n,a[8005] , i , j, b[8005],c[8005];
	while(scanf("%d",&n) == 1)
	{
		for(i = 0 ;i < n -1 ;i ++)
			scanf("%d",&a[i]);
		for(i = 1 ;i  <= n ;i ++ )
			b[i] = i;
		int visit[8001] = {0};
		for(i = n - 2; i >= 0 ;i --)
		{
			int len = 0;
			for(j = 1;j <= n; j ++) 
			{
				if(!visit[j])
				{
					if(len == a[i])
					{
						//printf("%d\n",j);
						c[i] = j;
						//a[i] = 1;
						visit[j] = 1;
					}
					len ++;
				}
			}
		}
		for(i = 1;i <= n ;i ++)
			if(!visit[i])
				printf("%d\n",i);
		for(i = 0 ;i < n -1; i ++)
			printf("%d\n",c[i]);
	}	
	return 0;
}
