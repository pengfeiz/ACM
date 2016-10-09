#include <iostream>
using namespace std;

const int maxn=5001;
const __int64 m=100000000;

unsigned __int64 a[maxn][2500];


int main()
{
	int n,i,j;
	unsigned __int64 q,b[2500],p,qq;
	memset(a,0,sizeof(a));
	a[2][1]=a[2][0]=1;
	a[3][0]=a[3][1]=1;
	for(n=4;n<=5000;n++)
	{
		p=11*(n-2)*(2*n-5);
		a[n][0]=a[n-1][0];
		for(j=1;j<=a[n-1][0];j++)
			a[n][j]=a[n-1][j]*p;
		for(j=1;j<a[n][0];j++)
		{
			a[n][j+1]+=a[n][j]/m;
			a[n][j]%=m;
		}
		while(a[n][a[n][0]]>=m)
		{
			a[n][a[n][0]+1]=a[n][a[n][0]]/m;
			a[n][a[n][0]]%=m;
			a[n][0]++;
		}
		memset(b,0,sizeof(b));
		b[0]=a[n-2][0];
		p=3*(3*n-8)*(3*n-10);
		for(j=1;j<=b[0];j++)
			b[j]=a[n-2][j]*p;
		for(j=1;j<b[0];j++)
		{
			b[j+1]+=b[j]/m;
			b[j]%=m;
		}
		while(b[b[0]]>=m)
		{
			b[b[0]+1]=b[b[0]]/m;
			b[b[0]]%=m;
			b[0]++;
		}
		p=5*(n-2)*(n-1);
		a[n][0]=b[0]>a[n][0]?b[0]:a[n][0];
		for(i=1;i<=a[n][0];i++)
			a[n][i]+=b[i];
		for(i=1;i<a[n][0];i++)
		{
			a[n][i+1]+=a[n][i]/m;
			a[n][i]%=m;
		}
		while(a[n][a[n][0]]>=m)
		{
			a[n][a[n][0]+1]=a[n][a[n][0]]/m;
			a[n][a[n][0]]%=m;
			a[n][0]++;
		}
		q=0;
		for(i=a[n][0];i>0;i--)
		{
			qq=a[n][i]+q;
			a[n][i]=qq/p;
			q=qq%p*m;
		}
		while(!a[n][a[n][0]])
		{
			a[n][0]--;
		}
//		a[n]=(11*(n-2)*(2*n-5)*a[n-1]+3*(3*n-8)*(3*n-10)*a[n-2])/(5*(n-2)*(n-1));
	}

	while(scanf("%d",&n)!=EOF)
	{
		unsigned __int64 t=0;
		q=1;
		for(i=1;i<=a[n][0];i++)
		{
			t=(t+a[n][i])*q;
			q*=10;
		}
		printf("%I64u\n",t);
	}
	return 0;
}