#include <iostream>
using namespace std;
#define MAX 10

bool d[MAX][MAX],b[MAX];
int a[MAX];
int n,m;

int dfs(int x)
{
	int i,t=0;
	b[x]=true;
	if(x==m)
	{
		a[m]++;
		return 1;
	}
	for(i=0;i<n;i++)
	{
		if(d[x][i]&&!b[i])
			t+=dfs(i);
	}
	a[x]+=t;
	return t;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int p,q,i;
	scanf("%d%d",&n,&m);
	memset(d,0,sizeof(d));
	while(scanf("%d%d",&p,&q)!=EOF)
		d[p][q]=true;
	for(i=0;i<n;i++)
		if(d[i][m])
		{
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			q=dfs(0);
			if(a[m]==a[i])
				break;
		}
	printf("%d\n",i);
	return 0;
}
		

