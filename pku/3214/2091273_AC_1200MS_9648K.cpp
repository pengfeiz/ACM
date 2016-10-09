#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

#define MAX 1048576

int a[MAX],n,b[MAX],c[MAX],m;

void dosth(int x)
{
	if(x*2<a[0])
		dosth(2*x);
	if(x*2+1<a[0])
	{
		m++;
		dosth(2*x+1);
	}
	c[0]++;
	c[c[0]]=a[x]-m;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,k,*num;
	num=(int *)malloc(sizeof(int));
	scanf("%d",&n);
	a[0]=1;
	m=c[0]=0;
	while(scanf("%d",&a[a[0]])!=EOF)
		a[0]++;
	dosth(1);
	b[0]=-999999999;
	k=0;
	for(i=1;i<=c[0];i++)
	{
		if(c[i]>=b[k])
		{
			k++;
			b[k]=c[i];
		}
		else
		{
			num=upper_bound(b+1,b+k,c[i]);
			*num=c[i];
		}
	}
	printf("%d\n",c[0]-k);
	return 0;
}
