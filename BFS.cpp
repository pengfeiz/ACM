//输入一个n*m阵列，判断有几组@组成图形(8个方向)


//z为8个方向，不可以处理太多记忆

#include <iostream>
using namespace std;
#define MAX 1001
#define gao_word '@'
//注意下面的z数组控制可走方向
struct gao
{int x,y;}a[MAX*MAX],z[8]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};

char s[MAX][MAX];
int n,m,t;
bool c[MAX][MAX];


void bfs(int x,int y)
{
	int qhead,qtail,j,xx,yy;
	qhead=qtail=0;
	a[0].x=x;
	a[0].y=y;
	c[x][y]=true;
	while(qhead<=qtail)
	{
		for(j=0;j<8;j++)
		{
			xx=a[qhead].x+z[j].x;
			yy=a[qhead].y+z[j].y;
			//这里控制字符
			if(s[xx][yy]==gao_word&&!c[xx][yy])
			{
				c[xx][yy]=true;
				qtail++;
				a[qtail].x=xx;
				a[qtail].y=yy;
			}
		}
		qhead++;
	}
}

void solve()
{
	int i,j;
	t=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			//这里控制字符
			if(s[i][j]==gao_word&&!c[i][j]&&++t)
				bfs(i,j);
	//控制输出格式
	printf("%d\n",t);
}


bool init()
{
	int i;
	memset(c,0,sizeof(c));
	memset(s,0,sizeof(s));
	scanf("%d%d",&n,&m);
	//有时候是通过EOF返回 这里注意
	if(!n&&!m)
		return false;
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	return true;
}

int main()
{
	while(init())
		solve();
	return 0;
}
