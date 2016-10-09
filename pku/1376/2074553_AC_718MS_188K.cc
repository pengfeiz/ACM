#include <iostream>
#include <string.h>
using namespace std;
int a[51][51],n,m;
int b[51][51];

int min(int x,int y)
{
	return x<y?x:y;
}

void dosth(int bx,int by,int ex,int ey,int t,int p)
{
	int q,i;
	if(bx==ex&&by==ey)
		return;
	for(i=1;i<=3&&bx-i>0;i++)
	{
		q=0;
		if(p==2)
			q=2;
		else if(p!=0)
			q=1;
		if(a[bx-i][by])
			break;
		if(b[bx-i][by]<=t+1+q)
			continue;
		else
			b[bx-i][by]=t+1+q;
		dosth(bx-i,by,ex,ey,t+q+1,0);
	}
	for(i=1;i<=3&&bx+i<n;i++)
	{
		q=0;
		if(p==0)
			q=2;
		else if(p!=2)
			q=1;
		if(a[bx+i][by])
			break;
		if(b[bx+i][by]<=t+1+q)
			continue;
		else
			b[bx+i][by]=t+1+q;
		dosth(bx+i,by,ex,ey,t+q+1,2);
	}
	for(i=1;i<=3&&by-i>0;i++)
	{
		q=0;
		if(p==1)
			q=2;
		else if(p!=3)
			q=1;
		if(a[bx][by-i])
			break;
		if(b[bx][by-i]<=t+q+1)
			continue;
		else
			b[bx][by-i]=t+q+1;
		dosth(bx,by-i,ex,ey,t+q+1,3);
	}
	for(i=1;i<=3&&by+i<m;i++)
	{
		q=0;
		if(p==3)
			q=2;
		else if(p!=1)
			q=1;
		if(a[bx][by+i])
			break;
		if(b[bx][by+i]<=t+1+q)
			continue;
		else
			b[bx][by+i]=t+q+1;
		dosth(bx,by+i,ex,ey,t+q+1,1);
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
	char s[10];
	int i,j,bx,by,ex,ey;
	while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
	{
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				scanf("%d",&bx);
				if(bx==1)
					a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=1;					
			}
		scanf("%d%d%d%d",&bx,&by,&ex,&ey);
		scanf("%s",s);
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++)
				b[i][j]=999999;
		if(strcmp(s,"south")==0)
			i=2;
		else if(strcmp(s,"west")==0)
			i=3;
		else if(strcmp(s,"east")==0)
			i=1;
		else
			i=0;
		b[bx][by]=0;
		if(a[bx][by])
			b[bx][by]==999999;
		else 
			dosth(bx,by,ex,ey,0,i);
		if(b[ex][ey]==999999)
			printf("-1\n");
		else
			printf("%d\n",b[ex][ey]);
	}
	return 0;
}
