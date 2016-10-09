#include <iostream>
using namespace std;

#define MAX 10

struct gao
{
	int x,y;
}z[4]={-1,0,0,1,1,0,0,-1};

char s[MAX][MAX];
int x,y,n=8,p,q;
char c[MAX*10];
char ss[MAX],m;

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,xx,yy,k;
	char cc,he;
	while(scanf("%s",s[0]),strcmp(s[0],"--"))
	{
		for(i=1;i<n;i++)
			scanf("%s",s[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(s[i][j]=='^')
				{
					x=i;
					y=j;
					p=0;
				}
				else if(s[i][j]=='>')
				{
					x=i;
					y=j;
					p=1;
				}
				else if(s[i][j]=='v')
				{
					x=i;
					y=j;
					p=2;
				}
				else if(s[i][j]=='<')
				{
					x=i;
					y=j;
					p=3;
				}
			}
		while(scanf("%s",c),strcmp(c,"#"))
		{
			if(strcmp(c,"move")==0)
			{
				scanf("%d",&q);
				for(k=0;k<q;k++)
				{
					xx=x+z[p].x;
					yy=y+z[p].y;
					s[x][y]='.';
					cc=s[x][y];
					if(xx<0||yy<0||xx>=n||yy>=n)
						break;
					x=xx;
					y=yy;
					while(s[xx][yy]!='.'&&!(xx<0||yy<0||xx>=n||yy>=n))
					{
						he=s[xx][yy];
						s[xx][yy]=cc;
						cc=he;
						m++;
						xx+=z[p].x;
						yy+=z[p].y;
					}
					if(xx>=0&&xx<n&&yy>=0&&yy<n)
						s[xx][yy]=cc;
				}
			}
			else
			{
				scanf("%s",c);
				if(strcmp(c,"left")==0)
					p=(p+3)%4;
				else if(strcmp(c,"right")==0)
					p=(p+1)%4;
				else
					p=(p+2)%4;
			}
		}
		if(p==0)
			s[x][y]='^';
		else if(p==1)
			s[x][y]='>';
		else if(p==2)
			s[x][y]='v';
		else
			s[x][y]='<';
		for(i=0;i<n;i++)
			printf("%s\n",s[i]);
		printf("\n");
	}
	return 0;
}



