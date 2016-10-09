#include <iostream>
using namespace std;
#define MAX 101

bool a[MAX][MAX];
int n,m,r,c;
char s[MAX];

int main()
{
	int i,j,k,l,t;
	bool fuck;
	while(scanf("%d%d%d%d",&n,&m,&r,&c),n||m||r||c)
	{
		t=0;
		fuck=true;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			for(j=0;j<m;j++)
				if(s[j]=='1')
					a[i][j]=true;
		}
		for(i=0;i<=n-r;i++)
			for(j=0;j<=m-c;j++)
			{
				if(a[i][j])
				{
					t++;
					for(k=0;k<r;k++)
						for(l=0;l<c;l++)
							a[i+k][l+j]=!a[i+k][l+j];
				}
			}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(a[i][j])
					fuck=false;
		if(fuck)
			printf("%d\n",t);
		else
			printf("-1\n");
	}
	return 0;
}
					