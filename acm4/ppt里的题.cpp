//ø…≈–∂œ÷ÿ∏¥±ﬂ


#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000001

bool a[MAX];
int n,t,root[MAX];


int getroot(int x)
{
	if(x!=root[x])
		root[x]=getroot(root[x]);
	return root[x];
}

int main()
{
	int i,tt=0,xx,yy,x,y;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&t);
	for(i=0;i<=n;i++)
		root[i]=i;
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&x,&y);
		xx=getroot(root[x]);
		yy=getroot(root[y]);
		if(xx==yy)
			continue;
		root[y]=xx;
	}
	for(i=1;i<=n;i++)
	{
		x=getroot(root[i]);
		if(!a[x])
		{
			tt++;
			a[x]=true;
		}
	}
	printf("%d\n",tt);
	return 0;
}