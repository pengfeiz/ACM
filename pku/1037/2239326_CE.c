#include <stdio.h>
#include <string.h>

#define MAX 21

__int64 a[MAX][MAX][2],n;
__int64 way[MAX],m;

bool u[MAX];

void dp()
{
	int i,j,k;
	memset(a,0,sizeof(a));
	a[n][1][0]=a[n][1][1]=1;
	for(i=n-1;i>0;i--)
		for(j=1;j<=n-i+1;j++)
		{
			for(k=1;k<j;k++)
				a[i][j][0]+=a[i+1][k][1];
			for(k=j+1;k<=n-i+1;k++)
				a[i][j][1]+=a[i+1][k-1][0];
		}
}

int pos(int s)
{
    int i,n;
    i=n=0;
    while(n<s)
    {
        i++;
        if(!u[i]) 
			n++;
    }
    u[i]=true;
    return i;
}      
    
void dosth(int d,__int64 m,int st,int b)
{
    __int64 c=0;
    int i,next;
    if(d>n)
	{
		printf("\n");
		return;
	}
    if(d!=1)
		printf(" ");
    for(i=2*st;i<=2*(n-d+1)+1&&c<m;i++) 
		if((i&1)==b||b==-1)
            c+=a[d][i>>1][i&1];
	i--;
    printf("%d",pos(i>>1));
    if(i&1)
		next=i>>1;
	else
		next=1;
    dosth(d+1,m-(c-a[d][i>>1][i&1]),next,(i&1)^1);
}  

void outt()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%5I64d ",a[i][j][0]);
		printf("\n");
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%5I64d ",a[i][j][1]);
		printf("\n");
	}
}

int main()
{
	int nn;
	scanf("%d",&nn);
	while(nn--)
	{
		scanf("%I64d%I64d",&n,&m);
		dp();
		memset(u,0,sizeof(u));
//		outt();        
		dosth(1,m,1,-1);

	}
	return 0;
}