//����һ��n*m���У��ж��м���@���ͼ��(8������)


//zΪ8�����򣬲����Դ���̫�����

#include <iostream>
using namespace std;
#define MAX 1001
#define gao_word '@'
//ע�������z������ƿ��߷���
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
			//��������ַ�
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
			//��������ַ�
			if(s[i][j]==gao_word&&!c[i][j]&&++t)
				bfs(i,j);
	//���������ʽ
	printf("%d\n",t);
}


bool init()
{
	int i;
	memset(c,0,sizeof(c));
	memset(s,0,sizeof(s));
	scanf("%d%d",&n,&m);
	//��ʱ����ͨ��EOF���� ����ע��
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
