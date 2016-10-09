#include <iostream>
using  namespace std;
#define MAX 25

bool a[MAX][MAX];
int n,m,l;

void solve(int x,int ll)
{
	int i;
	if(ll>l)
		l=ll;
	for(i=0;i<n;i++)
	{
		if(a[x][i])
		{
			a[x][i]=a[i][x]=false;
			solve(i,ll+1);
			a[x][i]=a[i][x]=true;
		}
	}
}

int main()
{
	int p,q,i;
	while(scanf("%d%d",&n,&m),n||m)
	{
		l=0;
		memset(a,0,sizeof(a));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&p,&q);
			a[p][q]=a[q][p]=true;
		}
		for(i=0;i<n;i++)
			solve(i,0);
		printf("%d\n",l);
	}
	return 0;
}
