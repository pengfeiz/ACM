#include <iostream>
using namespace std;

int n,m;
bool b[52];
int a[1000];
int c[1000];


void mul(int a[],int p)
{
	int i;
	for(i=1;i<=a[0];i++)
		a[i]*=p;
	for(i=1;i<a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(a[a[0]]>9)
	{
		a[a[0]+1]=a[a[0]]/10;
		a[a[0]]%=10;
		a[0]++;
	}
}


void jiecheng(int a[],int y)
{
	int i;
	a[0]=a[1]=1;
	for(i=y;i>1;i--)
		mul(a,i);
}


void add(int a[],int c[])
{
	int i;
	a[0]=a[0]>c[0]?a[0]:c[0];
	for(i=1;i<=a[0];i++)
		a[i]+=c[i];	
	for(i=1;i<a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(a[a[0]]>9)
	{
		a[a[0]+1]=a[a[0]]/10;
		a[a[0]]%=10;
		a[0]++;
	}
}


int main()
{
//	freopen("in.txt","r",stdin);
	char cc;
	int i,j,x,y,tim=0;
	while((cc=getchar())!='-')
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		getchar();
		a[0]=1;
		a[1]=0;
		for(i=1;i<=n;i++)
		{
			getchar();
			y=0;
			m=n-i;
			memset(c,0,sizeof(c));
			jiecheng(c,m);
			scanf("%d",&x);
			b[x]=true;
			for(j=1;j<x;j++)
				if(!b[j])
					y++;
			mul(c,y);
			add(a,c);
		}
		memset(c,0,sizeof(c));
		c[0]=c[1]=1;
		add(a,c);
		getchar();
		getchar();
		getchar();
		if(tim)
			printf(",");
		for(i=a[0];i>0;i--)
			printf("%d",a[i]);
		tim++;
	}
	printf("\n");
	return 0;
}