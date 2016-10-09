#include<iostream.h>
int pmax;
int pb,n;
const int M=22;
const int N=7;
int orders[M];
int ordere[M];
int ordern[M];
int left[N];
int tt;
bool use(int i)
{
	int j=orders[i];
	for(;j<ordere[i];j++)
	{
		if(left[j]<ordern[i])return 0;
	}
	return 1;
}
void get(int st,int ctotel)
{
	if(st==n){if(ctotel>tt)tt=ctotel;return;}
	int i,j,flag=0;
	for(i=st;i<n;i++)
	{
		if(!use(i))continue;
		flag=1;
		for(j=orders[i];j<ordere[i];j++)
			left[j]-=ordern[i];
		ctotel+=(ordere[i]-orders[i])*ordern[i];
		get(i+1,ctotel);
		for(j=orders[i];j<ordere[i];j++)
			left[j]+=ordern[i];
		ctotel-=(ordere[i]-orders[i])*ordern[i];
	}
	if(!flag)
		if(ctotel>tt)
                                              tt=ctotel;
}


int main()
{
	while(scanf("%d%d%d",&pmax,&pb,&n),pmax||pb||n)
	{
		int i;
		tt=0;
		for(i=0;i<pb;i++)
			left[i]=pmax;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&orders[i],&ordere[i],&ordern[i]);
		}
		get(0,0);
                                printf("%d\n",tt);
	}
	return 0;
}
