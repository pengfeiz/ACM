#include <iostream>
using namespace std;

#define maxn 1000002

int n,a[maxn],b[maxn],c[maxn],p,q;
int dis[maxn]={0};

int minn(int a,int b)
{return a<b?a:b;}
int maxx(int a,int b)
{return a>b?a:b;}


void sol()
{
	int ok,i;
	do{
		ok=0;
		for(i=1;i<=n;i++)
			if(dis[b[i]]<dis[a[i]]+c[i])
				dis[b[i]]=dis[a[i]]+c[i],ok=1;
		for(i=p+1;i<=q;i++)
			if(dis[i]<dis[i-1])
				dis[i]=dis[i-1],ok=1;
		for(i=q-1;i>=p;i--)
			if(dis[i]<dis[i+1]-1)
				dis[i]=dis[i+1]-1,ok=1;
	}while(ok);
	printf("%d\n",dis[q]);
}


int main()
{
	int i;
	scanf("%d",&n);
	p=1<<20;
	q=-1;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		a[i]--;
		p=minn(p,a[i]);
		q=maxx(q,b[i]);
	}
	sol();
	return 0;
}