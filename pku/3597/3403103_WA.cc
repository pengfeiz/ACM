#include <iostream>
using namespace std;

const int maxn=5001;

unsigned __int64 a[maxn];

int main()
{
	int n;
	a[0]=1;
	a[1]=1;
	for(n=2;n<=5000;n++)
		a[n]=(11*n*(2*n-1)*a[n-1]+3*(3*n-2)*(3*n-4)*a[n-2])/(5*n*(n+1));
	while(scanf("%d",&n)!=EOF)
		printf("%I64u\n",a[n-2]);
	return 0;
}