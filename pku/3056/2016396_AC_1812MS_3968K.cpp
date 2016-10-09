#include <stdio.h>
#include <string.h>
#define MAX 1000
int a[MAX],b[MAX][MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,l,t,k,q,p;
	scanf("%d",&l);
	while(l-->0)
	{
		p=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n-1;i++)
			if(a[i]==a[i+1])
			{
				p++;
				for(j=i;j<n-2;j++)
					a[j]=a[j+2];
				n-=2;
			}
		memset(b,0,sizeof(b));
		for(j=1;j<n;j+=2)
			for(i=0;i+j<n;i++)			
			{
				t=0;
				for(k=i;k<i+j;k+=2)
			        if(b[i][k+1]+b[k+2][i+j]>t)
						t=b[i][k+1]+b[k+2][i+j];
				if(a[i]==a[i+j])
					q=b[i+1][i+j-1]+1;	
				else
					q=b[i+1][i+j-1];
				if(t<q)
					t=q;
				b[i][i+j]=t;
			}
		printf("%d\n",b[0][n-1]+p);
	}
	return 0;
}

