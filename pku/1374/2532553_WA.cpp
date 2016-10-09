#include <iostream>
using namespace std;
#define MAX 27

int n,m;
int a[MAX][MAX];
int b[MAX][MAX];
char s[MAX*5][MAX*10];

struct gao
{
	int x,y;
}z[4]={0,1,1,0,0,-1,-1,0};

bool dfs(int x,int y)
{
	bool f=true;
	int xx,yy,j;
	a[x][y]=-1;
	for(j=0;j<4;j++)
	{
		xx=x+z[j].x;
		yy=y+z[j].y;
		if(a[xx][yy]>1)
			f=false;
		if(a[xx][yy]==1)
			if(!dfs(xx,yy))
				f=false;
	}
	if(f)
		a[x][y]=-1;
	else
		a[x][y]=-2;
	return f;
}



int main()
{
	int i,j,q,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(a,127,sizeof(a));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if(a[i][j]==1)
					dfs(i,j);
			}

		q=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if(a[i][j]==0&&a[i-1][j]!=0&&a[i+1][j]==0)
					b[i][j]=++q;
				else if(a[i][j]==0&&a[i][j-1]!=0&&a[i][j+1]==0)
					b[i][j]=++q;
			}
		
		for(k=0;k<n*5;k++)
			for(j=0;j<(m+1)*5;j++)
				s[k][j]=' ';
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i-1][j]==0||a[i][j]==0)
					for(k=(j-1)*5;k<=j*5;k++)
						s[(i-1)*3][k]='+';
				if(a[i][j]==0||a[i+1][j]==0)
					for(k=(j-1)*5;k<=j*5;k++)
						s[i*3][k]='+';
				if(a[i][j-1]==0||a[i][j]==0)					
					for(k=(i-1)*3;k<=i*3;k++)
						s[k][(j-1)*5]='+';
				if(a[i][j+1]==0||a[i][j]==0)					
					for(k=(i-1)*3;k<=i*3;k++)
						s[k][j*5]='+';
				if(a[i][j]==-1)
					for(k=(j-1)*5;k<=j*5;k++)
						s[(i-1)*3+1][k]=s[(i-1)*3+2][k]='+';
				if(a[i][j]==0&&b[i][j])
				{
					if(b[i][j]<10)
					{
						s[(i-1)*3+1][(j-1)*5+1]=s[(i-1)*3+1][(j-1)*5+2]='0';
						s[(i-1)*3+1][(j-1)*5+3]=b[i][j]+'0';
					}
					else if(b[i][j]<100)
					{
						s[(i-1)*3+1][(j-1)*5+1]='0';
						s[(i-1)*3+1][(j-1)*5+3]=b[i][j]%10+'0';
						b[i][j]/=10;
						s[(i-1)*3+1][(j-1)*5+2]=b[i][j]+'0';
					}
					else
					{
						s[(i-1)*3+1][(j-1)*5+3]=b[i][j]%10+'0';
						b[i][j]/=10;
						s[(i-1)*3+1][(j-1)*5+2]=b[i][j]%10+'0';
						b[i][j]/=10;
						s[(i-1)*3+1][(j-1)*5+1]=b[i][j]+'0';
					}
				}
			}
		}
		for(k=0;k<=3*n;k++)
		{
			for(j=m*5;j>=0;j--)
				if(s[k][j]!=' ')
					break;
			j++;
			s[k][j]='\0';
			printf("%s\n",s[k]);
		}
		printf("\n");
/*		
	for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				printf("%d",b[i][j]);
			printf("\n");
		}
*/
	}
	return 0;
}