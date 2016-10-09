#include <iostream>
using namespace std;

#define maxn 51000

int n,a[maxn],b[maxn],c[maxn],p,q;
int dis[maxn];

int min(int a,int b)
{return a<b?a:b;}
int max(int a,int b)
{return a>b?a:b;}


void sol()
{
	int ok,i,k;
	ok=1;
	while(ok)
	{
		ok=0;
		for(i=1;i<=n;++i)
			if(dis[b[i]]<(k=dis[a[i]]+c[i]))
				dis[b[i]]=k,ok=1;
		for(i=p+1;i<=q;++i)
			if(dis[i]<dis[i-1])
				dis[i]=dis[i-1],ok =1;
		for(i=p-1;i>=q;--i)
			if(dis[i]<dis[i+1]-1)
				dis[i]=dis[i+1]-1,ok=1;
	}
	printf("%d\n",dis[q]);
}


int main()
{
	int i;
	scanf("%d", &n);
	p=1<<20;
	q=0;
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d",a+i,b+i,c+i);
		++b[i];
		p=min(p,a[i]);
		q=max(q,b[i]);
	}
	sol();
	return 0;
}