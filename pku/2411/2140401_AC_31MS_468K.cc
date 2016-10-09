#include <iostream>
using namespace std;
#define MAX 17000
__int64 a[12][1<<11];
int b[MAX][2],n,m,tt;
void dosth(int t,int p,int q)
{
	if(t>m)
		return;
	if(t==m)
	{
		b[tt][0]=p;
		b[tt][1]=q;
		tt++;
		return;
	}
	dosth(t+2,p<<2,q<<2);
	dosth(t+1,(p<<1)|1,q<<1);
	dosth(t+1,p<<1,(q<<1)|1);
}

int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)&&(n,m))
	{
		tt=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		dosth(0,0,0);
		a[0][0]=1;
		for(i=0;i<n;i++)
			for(j=0;j<tt;j++)
				a[i+1][b[j][1]]+=a[i][b[j][0]];
		printf("%I64d\n",a[n][0]);
	}
	return 0;
}

