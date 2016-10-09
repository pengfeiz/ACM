#include <iostream>
using namespace std;
int a[10],n,q[10];
bool b[10][10];

bool dosth(int x,int m)
{
	int i;
	if(x==n-1)
		return true;
	if(!q[x])
	{
		if(dosth(x+1,x+2))
			return true;
		return false;
	}
	for(i=m;i<n;i++)
	{
		if(!q[x]||!q[i])
			continue;
		q[x]--;
		q[i]--;
		b[x][i]=true;
		b[i][x]=true;
		if(q[x]==0)
		{
			if(dosth(x+1,x+2))
				return true;
		}
		else if(dosth(x,i+1))
			return true;
		b[x][i]=false;
		b[i][x]=false;
		q[x]++;
		q[i]++;
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,k,j;
	scanf("%d",&k);
	while(k-->0)
	{
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		memcpy(q,a,sizeof(a));
		if(!dosth(0,1))
			printf("NO\n");
		else
		{
			printf("YES\n");
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(j)
						printf(" ");
					printf("%d",b[i][j]);
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}