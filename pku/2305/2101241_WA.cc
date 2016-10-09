#include <iostream>
using namespace std;
#define MAX 1001
char s[MAX],l;
int a[MAX],n,m,b[MAX],e[MAX];

void add()
{
	int i;
	for(i=1;i<=1000;i++)
		a[i]+=b[i];
	for(i=1;i<1000;i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
}

void dodo(char c)
{
	memset(e,0,sizeof(e));
	int i,y=c-'0';
	for(i=1;i<=b[0];i++)
		b[i]*=n;
	for(i=1;i<b[0];i++)
	{
		b[i+1]+=b[i]/10;
		b[i]%=10;
	}
	while(b[b[0]]>9)
	{
		b[b[0]+1]=b[b[0]]/10;
		b[b[0]]%=10;
		b[0]++;
	}
	memcpy(e,b,sizeof(b));	
	for(i=1;i<=b[0];i++)
		b[i]*=y;
	for(i=1;i<b[0];i++)
	{
		b[i+1]+=b[i]/10;
		b[i]%=10;
	}
	while(b[b[0]]>9)
	{
		b[b[0]+1]=b[b[0]]/10;
		b[b[0]]%=10;
		b[0]++;
	}
	add();
	memcpy(b,e,sizeof(b));
}

int find()
{
	int i;
	for(i=1000;i>0;i--)
		if(a[i]!=0)
			return i;
	return 1;
}

void dosth()
{
	int i,q;
	memset(b,0,sizeof(b));
	b[0]=b[1]=1;
	a[1]=s[l-1]-'0';
	for(i=l-2;i>=0;i--)
		dodo(s[i]);
	a[0]=find();
	q=0;
	for(i=a[0];i>0;i--)
	{
		q=a[i]+q*10;
		q%=m;
	}
	memset(b,0,sizeof(b));
	b[0]=1;
	if(q==0)
	{
		printf("0\n");
		return ;
	}
	while(q>0)
	{
		b[b[0]]=q%n;
		q/=n;
		b[0]++;
	}
	for(i=b[0]-1;i>0;i--)
		printf("%d",b[i]);
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
		l=strlen(s);
		b[0]=1;
		while(m>0)
		{
			b[b[0]]=m%10;
			m/=10;
			b[0]++;
		}
		m=0;
		for(i=b[0];i>0;i--)
			m=m*n+b[i];
		dosth();
	}
	return 0;
}
		


