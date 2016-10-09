#include <iostream>
#include <algorithm>
using namespace std;
char s[10][12],c[15];
int v[101][2001];
struct gao
{
	int x,y;
}q[101];
int minn(int a,int b)
{
	return a>b?b:a;
}
bool com(gao a,gao b)
{
	if(a.y<b.y)
		return true;
	if(a.y==b.y&&a.x<b.x)
		return true;
	return false;
}

int main()
{
	int b,m,n,i,j,color,t,w[100],x,p;
	while(scanf("%d%d",&m,&n)&&(m||n))
	{
		t=0;
		for(i=0;i<m;i++)
			scanf("%s",s[i]);
		for(i=0;i<n;i++)
		{
			scanf("%d%s",&b,c);
			for(j=0;j<m;j++)
				if(strcmp(c,s[j])==0)
					break;
			q[i].x=b;
			q[i].y=j;
		}
		sort(q,q+n,com);
		color=0;
		q[n].y=-1;
		q[n].x=x=b=0;
		for(i=0;i<=n;i++)
		{
			if(q[i].y!=color)
			{
				memset(v,0,sizeof(v));
				v[0][0]=true;
				for(j=1;j<=x;j++)
					for(p=0;p<=2000;p++)
					{
						if(v[j-1][p])
						{
							v[j][p]=true;
							v[j][p+w[j-1]]=true;
						}
					}
				for(j=(b+1)/2;j<=b;j++)
					if(v[x][j])
						break;
				t+=j;
				color=q[i].y;
				x=b=0;
			}
			b+=q[i].x;
			w[x++]=q[i].x;
		}
		printf("%d\n",t);
	}
	return 0;
}