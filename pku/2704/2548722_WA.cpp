#include <iostream>
using namespace std;

const int maxn=34;


int a[maxn][maxn];
int b[maxn][maxn];


int main()
{
	int i,j,n,x;
	while(scanf("%d",&n),n>=0)
	{
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<n;j++)
				a[i][j]=getchar()-'0';
		}
		memset(b,0,sizeof(b));
		b[0][0]=1;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(!a[i][j])
					continue;
				x=a[i][j];
				if(i+x<n)
					b[i+x][j]+=b[i][j];
				if(j+x<n)
					b[i][j+x]+=b[i][j];
			}
		printf("%d\n",b[n-1][n-1]);
	}
	return 0;
}