#include <iostream>
using namespace std;
#define MAX 20

int	a[MAX][MAX],n,m,dirty,x,y,minn,d[MAX][MAX][MAX];


struct gao
{
	int x,y;
}b[MAX];
bool c[MAX];


void build()
{
	int i,j;
	char c[MAX];
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

void bfs(int w)
{
	int i,x[MAX*MAX][2],xx[MAX*MAX][2],l=0;
	bool jud[MAX][MAX];
	memset(jud,0,sizeof(jud));
	x[0][0]=1;
	x[1][0]=b[w].x;
	x[1][1]=b[w].y;
	jud[b[w].x][b[w].y]=true;
	while(x[0][0])
	{
		xx[0][0]=0;
		for(i=1;i<=x[0][0];i++)
		{
			d[w][x[i][0]][x[i][1]]=l;
			if(!jud[x[i][0]-1][x[i][1]]&&a[x[i][0]-1][x[i][1]]>=0&&x[i][0]>0)
			{
				xx[0][0]++;
				xx[xx[0][0]][0]=x[i][0]-1;
				xx[xx[0][0]][1]=x[i][1];
				jud[xx[xx[0][0]][0]][xx[xx[0][0]][1]]=true;
			}
			if(x[i][1]>0&&!jud[x[i][0]][x[i][1]-1]&&a[x[i][0]][x[i][1]-1]>=0)
			{
				xx[0][0]++;
				xx[xx[0][0]][0]=x[i][0];
				xx[xx[0][0]][1]=x[i][1]-1;
				jud[xx[xx[0][0]][0]][xx[xx[0][0]][1]]=true;
			}
			if(x[i][0]<n-1&&!jud[x[i][0]+1][x[i][1]]&&a[x[i][0]+1][x[i][1]]>=0)
			{
				xx[0][0]++;
				xx[xx[0][0]][0]=x[i][0]+1;
				xx[xx[0][0]][1]=x[i][1];
				jud[xx[xx[0][0]][0]][xx[xx[0][0]][1]]=true;
			}
			if(x[i][1]<m-1&&!jud[x[i][0]][x[i][1]+1]&&a[x[i][0]][x[i][1]+1]>=0)
			{
				xx[0][0]++;
				xx[xx[0][0]][0]=x[i][0];
				xx[xx[0][0]][1]=x[i][1]+1;
				jud[xx[xx[0][0]][0]][xx[xx[0][0]][1]]=true;
			}
		}
		for(i=0;i<=xx[0][0];i++)
		{
			x[i][0]=xx[i][0];
			x[i][1]=xx[i][1];
		}
		l++;
	}
}

void findshortway()
{
	int i,j,k;
	for(i=0;i<dirty;i++)
		for(j=0;j<n;j++)
			for(k=0;k<m;k++)
				d[i][j][k]=99999999;
	for(i=0;i<dirty;i++)
		bfs(i);
}

	
void dfss(int num,int l,int tt)
{
	int i;
	if(tt==dirty)
	{
		if(l<minn)
			minn=l;
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
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&m,&n),n&&m)
	{
		minn=99999999;
		build();
		findshortway();
		memset(c,0,sizeof(c));
		c[0]=true;
		dfss(0,0,1);
		if(minn==99999999)
			minn=-1;
		printf("%d\n",minn);
	}
	return 0;
}
