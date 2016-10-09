#include <iostream>
using namespace std;
#define MAX 52

bool a[MAX][MAX][4],c[MAX][MAX];
int n,m;
int ma,tt;


void dosth(int x,int y,int t)
{
	if(t%2)
		a[x][y][0]=1;
	t/=2;
	if(t%2)
		a[x][y][1]=1;
	t/=2;
	if(t%2)
		a[x][y][2]=1;
	t/=2;
	if(t%2)
		a[x][y][3]=1;
}


int dfs(int x,int y)
{
	int tt=1;
	c[x][y]=true;
	if(!a[x][y][0]&&!c[x][y-1]&&y>1)
		tt+=dfs(x,y-1);
	if(!a[x][y][1]&&!c[x-1][y]&&x>1)
		tt+=dfs(x-1,y);
	if(!a[x][y][2]&&!c[x][y+1]&&y<m)
		tt+=dfs(x,y+1);
	if(!a[x][y][3]&&!c[x+1][y]&&x<n)
		tt+=dfs(x+1,y);
	return tt;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,p;
	ma=tt=0;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&p);
			dosth(i,j,p);
		}
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(!c[i][j])
			{
				tt++;
				p=dfs(i,j);
			}
			if(p>ma)
				ma=p;
		}
	printf("%d\n%d\n",tt,ma);
	return 0;
}

