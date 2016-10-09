#include <iostream>
using namespace std;

#define MAX 80

struct gao
{
	int x,y,n;
}b[9]={-2,1,0,-1,1,1,0,1,2,1,1,3,2,1,4,-1,2,5,0,2,6,1,2,7,0,3,8},c[MAX*MAX*10],cc[MAX*MAX*10];

int a[MAX][MAX][9];
int d[MAX][MAX][9],p[MAX],q;

char s[MAX][MAX];
int n,m,n1,n2,t,x[MAX],y[MAX];

void bfs()
{
	int i,j,k,xx,yy,ti,hx,hy;
	n1=t=0;
	for(i=0;i<q;i++)
	{
		if(s[n-1][y[i]]=='S')
		{
			for(k=0;k<9;k++)
			{
				xx=x[i]+b[k].x;
				yy=y[i]+b[k].y;
				if(xx<0||yy<0||xx>=n||yy>=m)
					continue;
				if(s[xx][yy]=='X')
					continue;
				if(s[xx][yy]=='T')
				{
					p[yy]=0;
					continue;
				}
				c[n1].x=x[i];
				c[n1].y=y[i];
				c[n1].n=b[k].n;
				a[c[n1].x][c[n1].y][c[n1].n]=s[xx][yy]-'0';
				d[c[n1].x][c[n1].y][c[n1].n]=0;
				n1++;
			}
			for(k=0;k<9;k++)
			{
				xx=x[i]-b[k].x;
				yy=y[i]-b[k].y;
				if(xx<0||yy<0||xx>=n||yy>=m)
					continue;
				if(s[xx][yy]=='X')
					continue;
				if(s[xx][yy]=='T')
				{
					p[yy]=0;
					continue;
				}
				c[n1].x=xx;
				c[n1].y=yy;
				c[n1].n=b[k].n;
				if(d[xx][yy][k]>0)
				{
					a[c[n1].x][c[n1].y][c[n1].n]=s[xx][yy]-'0';
					d[c[n1].x][c[n1].y][c[n1].n]=0;
					n1++;
				}
			}
		}
	}

	while(n1)
	{
		t++;
		n2=0;
		for(i=0;i<n1;i++)
		{
			for(j=0;j<9;j++)
			{
				xx=c[i].x+b[j].x;
				yy=c[i].y+b[j].y;
				if(xx<0||yy<0||xx>=n||yy>=m)
					continue;
				if(s[xx][yy]=='X')
					continue;
				if(s[xx][yy]=='T')
				{
					if(p[yy]>a[c[i].x][c[i].y][c[i].n])
						p[yy]=a[c[i].x][c[i].y][c[i].n];
					continue;
				}
				else
					ti=s[xx][yy]-'0';
				if(a[c[i].x][c[i].y][j]>a[c[i].x][c[i].y][c[i].n]+ti)
				{
					a[c[i].x][c[i].y][j]=a[c[i].x][c[i].y][c[i].n]+ti;
					if(d[c[i].x][c[i].y][j]!=t)
					{
						d[c[i].x][c[i].y][j]=t;
						cc[n2].x=c[i].x;
						cc[n2].y=c[i].y;
						cc[n2].n=j;
						n2++;
					}
				}
			}
			hx=c[i].x+b[c[i].n].x;
			hy=c[i].y+b[c[i].n].y;
			for(j=0;j<9;j++)
			{
				xx=hx-b[j].x;
				yy=hy-b[j].y;
				if(xx<0||yy<0||xx>=n||yy>=m)
					continue;
				if(s[xx][yy]=='X')
					continue;
				if(s[xx][yy]=='T')
				{
					if(p[yy]>a[c[i].x][c[i].y][c[i].n])
						p[yy]=a[c[i].x][c[i].y][c[i].n];
					continue;
				}
				else
					ti=s[xx][yy]-'0';
				if(a[xx][yy][j]>a[c[i].x][c[i].y][c[i].n]+ti)
				{
					a[xx][yy][j]=a[c[i].x][c[i].y][c[i].n]+ti;
					if(d[xx][yy][j]!=t)
					{
						d[xx][yy][j]=t;
						cc[n2].x=xx;
						cc[n2].y=yy;
						cc[n2].n=j;
						n2++;
					}
				}
			}
		}
		n1=n2;
		for(i=0;i<n1;i++)
		{
			c[i].x=cc[i].x;
			c[i].y=cc[i].y;
			c[i].n=cc[i].n;
		}
	}
}


int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d%d",&m,&n),m||n)
	{
		q=0;
		memset(a,127,sizeof(a));
		memset(d,0,sizeof(d));
		memset(p,127,sizeof(p));
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				getchar();
				scanf("%c",&s[i][j]);
			}
			s[i][m]='\0';
		}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(s[j][i]=='S')
				{
					x[q]=j;
					y[q]=i;
					q++;
				}
		bfs();
		t=9999999;
		for(j=0;j<m;j++)
		{
			if(s[0][j]=='T')
			{
				if(t>p[j])
					t=p[j];
			}
		}
		if(t==9999999)
			printf("-1\n");
		else
			printf("%d\n",t);
	}
	return 0;
}

	