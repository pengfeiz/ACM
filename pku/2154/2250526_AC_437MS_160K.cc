#include <iostream>
#include <math.h>
using namespace std;

#define MAX 20001
#define MAX2 50

//打素数表
bool prime(__int64 x)
{
	__int64 i,p=(__int64)sqrt(x*1.0);
	for(i=2;i<=p;i++)
		if(x%i==0)
			return false;
	return true;
}


__int64 t,a[MAX],n,p,b[MAX2][2],c[MAX2];


//初始化
void first()
{	
	__int64 nn=n,i;
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	t=0;
	for(i=1;a[i]<=nn&&i<=a[0];i++)
	{
		if(nn%a[i]==0)
		{
			b[0][0]++;
			b[b[0][0]][0]=a[i];
			while(nn%a[i]==0)
			{
				b[b[0][0]][1]++;
				nn/=a[i];
			}
		}
	}
	if(nn>1)
	{
		b[0][0]++;
		b[b[0][0]][0]=nn;
		b[b[0][0]][1]=1;
	}
	c[0]=b[0][0];

}

//计算a^b Mod n
__int64 model(__int64 a,__int64 b,__int64 p)
{
	__int64 d;
	d=1;
	while(b)
	{
		if(!a&&b)
			return 0;
		if(b&1)
			d=(d*a)%p;
		b=b>>1;
		a=(a*a)%p;
	}
	return d;
}


void second(__int64 x)
{
	__int64 i,j;
	if(x>c[0])
	{
		__int64 nn=n,w=1;
		for(i=1;i<=c[0];i++)
		{
			for(j=0;j<c[i];j++)
			{
				w*=b[i][0];
				nn/=b[i][0];
			}
			if(c[i]<b[i][1])
			{
				nn/=b[i][0];
				nn*=(b[i][0]-1);
			}
		}
		nn%=p;
		t+=nn*model(n,w-1,p);
		t%=p;
		return;
	}
	for(i=0;i<=b[x][1];i++)
	{
		c[x]=i;
		second(x+1);
	}
}


void solve()
{
	first();
	second(1);
	printf("%I64d\n",t);
}


int main()
{
//	freopen("in.txt","r",stdin);
	__int64 i,nn,ft;
	a[0]=0;
	ft=(__int64)sqrt(1000000000)+1;
	for(i=2;i<=ft;i++)
		if(prime(i))
		{
			a[0]++;
			a[a[0]]=i;
		}
	scanf("%I64d",&nn);
	while(nn--)
	{
		scanf("%I64d%I64d",&n,&p);
		solve();
	}
	return 0;
}