#include <stdio.h>
#include <stdlib.h>
#define MAX 50001

int nd[MAX], st[MAX];
int D,X,Y,tt,hdX,hdY,N,K;
void init()
{
	int i;
	tt=0;
	for(i=0;i<=N;i++)
		nd[i]=st[i]=0;
}
int get_id(int x)
{
	int root;
	if (nd[x]==0)
	{
		st[x]=0;
		return x;
	}
	root=get_id(nd[x]);
	st[x]=(st[x]+st[nd[x]])%3;
	nd[x]=root;
	return root;
}

int main()
{
	int i;
	scanf("%d%d",&N,&K);
	init();
	for(i=0;i<K&&scanf("%d%d%d",&D,&X,&Y)!=-1;i++)
	{
		if(X>N||Y>N)
		{
			tt++;
			continue;
		}
		if (X==Y&&D==2)
		{
			tt++;
			continue;
		}
		hdX=get_id(X);
		hdY=get_id(Y);
		if(hdX!=hdY)
		{
			nd[hdY]=hdX;
			st[hdY]=(st[X]+D+2-st[Y])%3;
		}
		else
		{
			if((st[Y]-st[X]+3)%3!=D-1)
				tt++;
		}
	}
	printf("%d\n",tt);
	return 0;
}


	

