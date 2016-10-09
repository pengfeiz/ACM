#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 26

struct gao
{
	char s[100];
	int n,p;
}s[MAX],c[MAX];

bool a[MAX][MAX],b[MAX][MAX],q[MAX]; 

int d[MAX],na,nb;


bool com(gao a,gao b)
{return strcmp(a.s,b.s)<0;}


bool dfs(int x)
{
	int i;
	if(x)
	{
		for(i=0;i<na;i++)
			if(d[i]>0&&(a[s[x-1].p][s[i].p]^b[d[x-1]][d[i]]))
				return false;
	}
	if(x==na)
		return true;
	for(i=0;i<na;i++)
	{
		if(!q[i]&&s[x].n==c[i].n)
		{
			d[x]=i;
			q[i]=true;
			if(dfs(x+1))
				return true;
			q[i]=false;
			d[x]=-1;
		}
	}
	return false;
}

int main()
{
	bool f;
	int n,i,j,k;
	char ss[MAX],cc[MAX];
	while(scanf("%d",&n),n)
	{
		f=true;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(s,0,sizeof(s));
		memset(c,0,sizeof(c));
		na=nb=0;
		for(i=0;i<n;i++)
		{
			scanf("%s%s",ss,cc);
			for(j=0;j<na;j++)
				if(!strcmp(ss,s[j].s))
					break;
			if(j==na)
			{
				strcpy(s[na].s,ss);
				s[na].p=na;
				na++;
			}
			for(k=0;k<na;k++)
				if(!strcmp(cc,s[k].s))
					break;
			if(k==na)
			{
				strcpy(s[na].s,cc);
				s[na].p=na;
				na++;
			}
			s[j].n++;
			s[k].n++;
			a[j][k]=true;
		}
		for(i=0;i<n;i++)
		{
			scanf("%s%s",ss,cc);
			for(j=0;j<nb;j++)
				if(!strcmp(ss,c[j].s))
					break;
			if(j==nb)
			{
				strcpy(c[nb].s,ss);
				c[nb].p=nb;
				nb++;
			}
			for(k=0;k<nb;k++)
				if(!strcmp(cc,c[k].s))
					break;
			if(k==nb)
			{
				strcpy(c[nb].s,cc);
				c[nb].p=nb;
				nb++;
			}
			c[j].n++;
			c[k].n++;
			b[j][k]=true;
		}
		sort(s,s+na,com);
		memset(d,0xff,sizeof(d));
		memset(q,0,sizeof(q));
		dfs(0);
		for(i=0;i<na;i++)
			printf("%s/%s\n",s[i].s,c[d[i]].s);
		printf("\n");
	}
	return 0;
}

		


