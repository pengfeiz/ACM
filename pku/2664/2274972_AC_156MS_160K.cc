#include <iostream>
using namespace std;
#define MAX 10000

int a[MAX];
int main()
{
	int n,m,c,r,i,x,t,y,tim=0;
	memset(a,0,sizeof(a));
	while(scanf("%d",&n),n)
	{
		tim++;
		t=1;
		scanf("%d",&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x]=tim;
		}
		while(m--)
		{
			scanf("%d%d",&c,&r);
			y=0;
			for(i=0;i<c;i++)
			{
				scanf("%d",&x);
				if(a[x]==tim)
					y++;
			}
			if(y<r)
				t=0;
		}
		if(t)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
		