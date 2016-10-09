#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int p1,p2,n;
int a[MAX],b[MAX],d[MAX];


void bellman()
{
	int i;
	bool f;
	do{
		f=false;
		for(i=0;i<n;i++)
			if(d[b[i]]<d[a[i]]+2)
				d[b[i]]=d[a[i]]+2,f=true;
		for(i=p1;i<p2;i++)
			if(d[i+1]<d[i])
				d[i+1]=d[i],f=true;
		for(i=p2;i>p1;i--)
			if(d[i-1]<d[i]-1)
				d[i-1]=d[i]-1,f=true;
	}while(f);
	printf("%d\n",d[p2]-d[p1]);
}


int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	memset(d,0,sizeof(d));
	scanf("%d",&n);
	p1=1<<30;
	p2=-1<<30;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]>b[i])
			swap(a[i],b[i]);
		b[i]++;
		p1=p1>a[i]?a[i]:p1;
		p2=p2<b[i]?b[i]:p2;
	}
	bellman();
	return 0;
}