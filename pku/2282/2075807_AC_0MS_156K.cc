#include <iostream>
#include <algorithm>
using namespace std;

int t[10],y;

void dosth(int n,int m,int x)
{
	int k;
	while(n%10&&n<=m)
	{
		k=n;
		while(k>0)
		{
			t[k%10]+=x;
			k/=10;
		}
		n++;
	}
	while(m%10!=9&&m>n)
	{
		k=m;
		while(k>0)
		{
			t[k%10]+=x;
			k/=10;
		}
		m--;
	}
	if(n==m)
	{
		k=n;
		while(k>0)
		{
			t[k%10]+=x;
			k/=10;
		}
		return;
	}
	for(k=0;k<10;k++)
		t[k]+=x*(m+1-n)/10;
	m=(m-9)/10;
	n/=10;
	dosth(n,m,10*x);
}

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)&&(a||b))
	{
		memset(t,0,sizeof(t));
		if(a>b)
			swap(a,b);
		y=b;
		dosth(a,b,1);
		for(a=0;a<10;a++)
		{
			if(a)
				printf(" ");
			printf("%d",t[a]);
		}
		printf("\n");
	}
	return 0;
}