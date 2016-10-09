#include <iostream>
using namespace std;

const int maxn=1001;
const int maxm=10;

int a[maxn][maxm];
int dptable[maxn][maxn];
int n,m;

int main()
{
//	freopen("D.09.dat","r",stdin);
	int i,j,b[maxm],k,t,q;

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);

	memset(dptable,0,sizeof(dptable));

	for(i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
/*		for(j=0;j<=n;j++)
			if(dptable[i][j]<dptable[i-1][j])
				dptable[i][j]=dptable[i-1][j];*/
		for(j=i;j<=n;j++)
		{
			for(k=0;k<m;k++)
				b[k]+=a[j][k];
			for(k=1;k<m;k++)
				if(b[0]<=b[k])
					break;
			q=j-i;
			if(k==m)
			{
				for(t=0;t<i;t++)
					if(dptable[j][t+q]<dptable[i-1][t]+1)
						dptable[j][t+q]=dptable[i-1][t]+1;
			}
			else
			{
				for(t=0;t<i;t++)
					if(dptable[j][t+q]<dptable[i-1][t])
						dptable[j][t+q]=dptable[i-1][t];
			}
		}
	}
	for(i=0;i<n;i++)
		if(dptable[n][i]>(n-i)/2)
			break;
	if(i==n)
		printf("-1\n");
	else
		printf("%d\n",i);
	return 0;
}

