#include <iostream>
using namespace std;

const int MAX=8;

int a[MAX+2][MAX+2],aa[MAX+2][MAX+2];
int b[MAX+2][MAX+2];
int x1,y1,x2,y2;

int xx[8]={-1,-1,0,1,1,1,0,-1};
int yy[8]={0,1,1,1,0,-1,-1,-1};
bool ff;


bool dosth()
{
	int i,j,k,x,y;
	for(i=1;i<=MAX;i++)
		for(j=1;j<=MAX;j++)
			aa[i][j]=a[i][j];
	memset(a,0,sizeof(a));
	for(i=1;i<=MAX;i++)
		for(j=1;j<=MAX;j++)
		{
			if(aa[i][j])
			{
				for(k=0;k<8;k++)
				{
					x=i+xx[k];
					y=j+yy[k];
					if(b[x][y]!=2)
						continue;
					if(x==x2&&y==y2)
						return true;
					a[x][y]=true;
				}
			}
		}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int tt,i,j;
	char s[MAX+2][MAX+2];
	scanf("%d",&tt);
	while(tt--)
	{
		memset(a,0,sizeof(a));
		memset(b,0xff,sizeof(b));
		for(i=1;i<=MAX;i++)
		{
			scanf("%s",s[i]+1);
			for(j=1;j<=MAX;j++)
			{
				if(s[i][j]=='.')
					b[i][j]=2;
				else if(s[i][j]=='D')
					b[i][j]=1;
				else
					b[i][j]=0;
			}
		}
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		x1=9-x1;
		x2=9-x2;
		a[x1][y1]=true;
		do
		{
			ff=false;
			if(dosth())
			{
				printf("White\n");
				break;
			}
			a[x2+1][y2+1]=a[x2+1][y2-1]=false;

			for(i=1;i<=MAX;i++)
				for(j=1;j<=MAX;j++)
					if(a[i][j])
						ff=true;
			if(!ff)
			{
				printf("Black\n");
				break;
			}
			if(x2==8)
			{
				printf("Black\n");
				break;
			}
			if(a[x2+1][y2]||b[x2+1][y2]==0)
			{
				printf("White\n");
				break;
			}
			x2++;
		}while(x2<=MAX);
	}
	return 0;
}