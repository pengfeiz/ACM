#include <iostream>
using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))

int kase=0;
int n,t;
int a[32];
char name[32][32];

int read()
{
	int i,j,k,tt;
	char name1[30],name2[30];
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&t);
	if(!(n||t))
		return 0;
	for(i=0;i<n;i++)
    {
		scanf("%s",name[i]);
		a[i]=0;
    }
	for(k=0;k<t;k++)
    {
		scanf("%s%s%d\n",name1,name2,&tt);
		for(i=0;strcmp(name1,name[i]);i++);
		for(j=0;strcmp(name2,name[j]);j++);
		a[i]-=tt;
		a[j]+=tt;
    }
	return 1;
}

void solve()
{
	int src,dst,tt;
	printf("Case #%d\n",++kase);
	while(1)
    {
		for(src=0;src<n;src++)
			if(a[src]>0) 
				break;
		for(dst=0;dst<n;dst++)
			if(a[dst]<0)
				break;
		if(src==n||dst==n)
			break;
		tt=MIN(a[src],-a[dst]);
		a[src]-=tt;
		a[dst]+=tt;
		printf("%s %s %d\n",name[src],name[dst],tt);
    }
	printf("\n");
}

int main()
{
	while (read())
		solve();
	return 0;
}
