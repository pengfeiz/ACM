#include <iostream>
using namespace std;

#define MAX 50001
int a[MAX],b[MAX],c[MAX],d[MAX];
int p1,p2,n,m;

int minn(int a,int b)
{return a<b?a:b;}
int maxx(int a,int b)
{return a>b?a:b;}


int bellman_ford()
{
	int i;
	bool f;
	do{
		f=false;
		for(i=p1;i<p2;i++)
			if(d[i+1]<d[i])
				d[i+1]=d[i],f=true;
		for(i=p2;i>p1;i--)
			if(d[i-1]<d[i]-1)
				d[i-1]=d[i]-1,f=true;
		for(i=0;i<n;i++)
			if(d[b[i]]<d[a[i]]+c[i])
				d[b[i]]=d[a[i]]+c[i],f=true;
	}while(f);
	return d[p2];
}

int main()
{
	int i;
	scanf("%d",&n);
	p1=1<<30;
	p2=-1<<30;
	memset(d,0,sizeof(d));
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		a[i]--;
		p1=minn(p1,a[i]);
		p2=maxx(p2,b[i]);
	}
	printf("%d\n",bellman_ford());
	return 0;
}
		
	
