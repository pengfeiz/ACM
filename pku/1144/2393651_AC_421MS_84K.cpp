#include <iostream>
using namespace std;

#define MAX 101

bool a[MAX];
bool b[MAX][MAX];
int n,t;

int dfs(int x)
{
	int i,t=1;
	a[x]=true;
	for(i=1;i<=n;i++)
		if((b[x][i]||b[i][x])&&!a[i])
			t+=dfs(i);
	return t;
}
int main()
{
	int i,q,p,j;
	char c;
	while(scanf("%d",&n),n)
	{
		t=0;
		memset(b,0,sizeof(b));
		while(scanf("%d",&q),q)
		{
			scanf("%c",&c);
			while(c!='\n')
			{
				scanf("%d",&p);
				b[q][p]=b[p][q]=true;
				scanf("%c",&c);
			}
		}
		for(i=1;i<=n;i++)
		{
			memset(a,0,sizeof(a));
			a[i]=true;
			q=-1;
			for(j=1;j<=n;j++)
				if((b[i][j]||b[j][i])&&!a[j])
				{
					q=dfs(j);
					break;
				}
			if(q==n-1)
				t++;
		}
		printf("%d\n",n-t);
	}
	return 0;
}