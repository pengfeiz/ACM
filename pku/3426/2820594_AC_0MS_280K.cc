#include <iostream>
using namespace std;

struct node
{int x,y,sta,fa;}que[1010];

int n;
int door[55][55][2];
bool flag[55][55][4];
int f;

int pri(int now)
{
    if(que[now].fa!=now)
	pri(que[now].fa);
    printf("%d %d\n",que[now].y,que[now].x);
    return 0;
}

void bfs()
{
    int p=0,q=0;
    int x,y,sta;
    que[0].x=1;
    que[0].y=1;
    que[0].sta=0;
    que[0].fa=0;
    memset(flag,0,sizeof(flag));
    flag[1][1][0]=1;
    flag[1][1][3]=1;
    while(p<=q)
    {
	if(que[p].sta!=0)
	{
            x=que[p].x-1;
	    y=que[p].y;
	    sta=-1;
	    if(door[x][y][1]==2)
		sta=1;
            if(door[x][y][1]==4)
		sta=3;
            if(sta>-1&&!flag[x][y][sta])
            {
		que[++q].x=x;
		que[q].y=y;
		que[q].sta=sta;
		que[q].fa=p;
		flag[x][y][sta]=1;
		if(x==n&&y==n)
		{
                    f=1;
                    pri(q);
                    break;
		}
            }
	}
	if(que[p].sta!=1)
	{
            x=que[p].x;
            y=que[p].y+1;
            sta=-1;
            if(door[que[p].x][que[p].y][0]==1)
		sta=0;
            if(door[que[p].x][que[p].y][0]==3)
		sta=2;
            if(sta>-1&&flag[x][y][sta]==0)
            {
		que[++q].x=x;
		que[q].y=y;
		que[q].sta=sta;
		que[q].fa=p;
		flag[x][y][sta]=1;
		if(x==n&&y==n)
		{
                    f=1;
                    pri(q);
                    break;
		}
            }
	}
	if(que[p].sta!=2)
	{
            x=que[p].x+1;
            y=que[p].y;
            sta=-1;
            if(door[que[p].x][que[p].y][1]==1)
		sta=1;
            if(door[que[p].x][que[p].y][1]==3)
		sta=3;
            if(sta>-1&&flag[x][y][sta]==0)
            {
		que[++q].x=x;
		que[q].y=y;
		que[q].sta=sta;
		que[q].fa=p;
		flag[x][y][sta]=1;
		if(x==n&&y==n)
		{
                    f=1;
                    pri(q);
                    break;
		}
            }
	}
	if(que[p].sta!=3)
	{
            x=que[p].x;
            y=que[p].y-1;
            sta=-1;
            if(door[x][y][0]==2)
		sta=0;
            if(door[x][y][0]==4)
		sta=2;
            if(sta>-1&&flag[x][y][sta]==0)
            {
		que[++q].x=x;
		que[q].y=y;
		que[q].sta=sta;
		que[q].fa=p;
		flag[x][y][sta]=1;
		if(x==n&&y==n)
		{
                    f=1;
                    pri(q);
                    break;
		}
            }
	}
	++p;
    }
    return;
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
	for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
		scanf("%d%d",&door[i][j][0],&door[i][j][1]);
	f=0;
	bfs();
	if(!f)
            printf("0\n");
    }
    return 0;
}
