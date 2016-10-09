#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

bool a[MAX][MAX]={0},b[MAX]={0};
int root[MAX]={0},n,m,ans;
vector<int> c[MAX];
void dfs(int x)
{
	int i,y,j,l;
	b[x]=true;
	root[x]=0;
	l=c[x].size();
	for(i=0;i<l;i++)
	{	
		y=c[x][i];
		if(!b[y])
			dfs(y);
		a[x][y]=true;
		for(j=1;j<=n;j++)
			if(a[y][j])
				a[x][j]=true;
	}
	for(i=1;i<=n;i++)
		if(a[x][i])
			root[x]++;
	ans-=root[x];
}
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		c[x].push_back(y);
	}
	ans=n*(n-1)/2;
	for(i=1;i<=n;i++)
	{
		if(!b[i])
			dfs(i);
	}
	printf("%d\n",ans);
	return 0;
}