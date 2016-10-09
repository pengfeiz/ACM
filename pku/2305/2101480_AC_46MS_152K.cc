#include <iostream>
using namespace std;
#define MAX 1005
char s[MAX];
int a[MAX],n,m;

void dosth()
{
	int i,q;
	for(i=0;i<a[0];i++)
		a[i+1]=s[i]-'0';
	q=0;
	for(i=1;i<=a[0];i++)
	{
		q=a[i]+q*n;
		q%=m;
	}
	memset(a,0,sizeof(a));
	a[0]=1;
	if(q==0)
	{
		printf("0\n");
		return;
	}
	while(q>0)
	{
		a[a[0]]=q%n;
		q/=n;
		a[0]++;
	}
	for(i=a[0]-1;i>0;i--)
		printf("%d",a[i]);
	printf("\n");
}

int main()
{
	int i;
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n),n)
	{
		memset(a,0,sizeof(a));
		scanf("%s%d",s,&m);
		a[0]=1;
		while(m>0)
		{
			a[a[0]]=m%10;
			m/=10;
			a[0]++;
		}
		m=0;
		for(i=a[0]-1;i>0;i--)
			m=m*n+a[i];
		a[0]=strlen(s);
		dosth();
	}
	return 0;
}
		


