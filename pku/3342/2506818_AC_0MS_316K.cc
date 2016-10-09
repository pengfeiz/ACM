#include <iostream>
#include <string.h>
using namespace std;

#define MAX 203

int n,t;
char s[MAX][MAX];
int a[MAX],b[MAX][2];
bool c[MAX][2];
bool f;


int maxx(int a,int b)
{return a>b?a:b;}


void dfs(int x)
{
	int i;
	bool tt=false;
	b[x][0]=1;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			dfs(i);
			tt=true;
			b[x][0]+=b[i][1];
			if(c[i][1]==true)
				c[x][0]=true;
			if(b[i][1]>b[i][0])
			{
				b[x][1]+=b[i][1];
				if(c[i][1]==true)
					c[x][1]=true;
			}
			else if(b[i][1]<b[i][0])
			{
				b[x][1]+=b[i][0];
				if(c[i][0]==true)
					c[x][1]=true;
			}
			else
			{
				b[x][1]+=b[i][0];
				c[x][1]=true;
			}
		}
	}
	if(!tt)
	{
		b[x][0]=1;
		b[x][1]=0;
	}
}


int main()
{
//	freopen("in.txt","r",stdin);
	int i,s1,s2;
	char c1[MAX],c2[MAX];
	while(scanf("%d",&n),n)
	{
		f=false;
		memset(a,127,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		t=1;
		scanf("%s",s[0]);
		for(i=1;i<n;i++)
		{
			scanf("%s%s",c1,c2);
			for(s1=0;s1<t;s1++)
				if(strcmp(c2,s[s1])==0)
					break;
			if(s1==t)
			{
				strcpy(s[s1],c2);
				t++;
			}
			for(s2=0;s2<t;s2++)
				if(strcmp(c1,s[s2])==0)
					break;
			if(s2==t)
			{
				strcpy(s[s2],c1);
				t++;
			}
			a[s2]=s1;
		}
		dfs(0);
		printf("%d ",maxx(b[0][0],b[0][1]));
		if(b[0][0]==b[0][1])
			f=true;
		else if(b[0][0]>b[0][1]&&c[0][0]==true)
			f=true;
		else if(b[0][0]<b[0][1]&&c[0][1]==true)
			f=true;
		if(!f)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

