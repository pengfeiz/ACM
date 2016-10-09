#include <iostream>
using namespace std;
#define MAX 11
#define MAX2 20

int	a[MAX2][MAX2],n,m,dirty,x,y,min,d[MAX][MAX2][MAX2];;


struct gao
{
	int x,y;
}b[MAX];
bool c[MAX];


void build()
{
	int i,j;
	char c[MAX2];
	dirty=1;
	for(i=0;i<n;i++)
	{
		scanf("%s",c);
		for(j=0;j<m;j++)
		{
			if(c[j]=='.')
				a[i][j]=0;
			else if(c[j]=='x')
				a[i][j]=-1;
			else if(c[j]=='*')
			{
				b[dirty].x=i;
				b[dirty].y=j;
				dirty++;
				a[i][j]=1;
			}
			else 
			{
				b[0].x=i;
				b[0].y=j;
				a[i][j]=2;
				x=i;
				y=j;
			}
		}
	}
}

void dfs(int i,int x,int y,int l)
{
	if(d[i][x][y]<=l||a[x][y]<0)
		return;
	d[i][x][y]=l;
	if(x>0)
		dfs(i,x-1,y,l+1);
	if(y>0)
		dfs(i,x,y-1,l+1);
	if(x<n-1)
		dfs(i,x+1,y,l+1);
	if(y<m-1)
		dfs(i,x,y+1,l+1);
}

void findshortway()
{
	memset(d,127,sizeof(d));
	int i;
	for(i=0;i<dirty;i++)
		dfs(i,b[i].x,b[i].y,0);
}

	
void dfss(int num,int l,int tt)
{
	int i;
	if(tt==dirty)
	{
		if(l<min)
			min=l;
		return;
	}
	for(i=0;i<dirty;i++)
	{
		if(!c[i])
		{
			c[i]=true;
			dfss(i,l+d[num][b[i].x][b[i].y],tt+1);
			c[i]=false;
		}
	}
}


int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&m,&n),n&&m)
	{
		min=99999999;
		build();
		findshortway();
		memset(c,0,sizeof(c));
		c[0]=true;
		dfss(0,0,1);
		if(min==99999999)
			min=-1;
		printf("%d\n",min);
	}
	return 0;
}
