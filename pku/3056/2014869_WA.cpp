#include <stdio.h>
#include <string.h>
#define MAX 1000
int a[MAX],b[MAX][MAX];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,l,t;
	scanf("%d",&l);
	while(l-->0)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(b,0,sizeof(b));
		for(j=1;j<n;j++)
			for(i=0;i+j<n;i++)			
			{
				t=b[i][i+j-1]>b[i+1][i+j]?b[i][i+j-1]:b[i+1][i+j];
				if(a[i]==a[i+j])
					b[i][i+j]=t>b[i+1][i+j-1]+1?t:b[i+1][i+j-1]+1;	
				else
					b[i][i+j]=t;
			}
		printf("%d\n",b[0][n-1]);
	}
	return 0;
}

