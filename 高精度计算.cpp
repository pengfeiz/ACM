#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100000
char aa[MAX],bb[MAX];

int max(int a,int b)
{return a>b?a:b;}

void add(int a[],int b[],int c[])
{
	int i;
	c[0]=max(a[0],b[0]);
	for(i=1;i<=c[0];i++)
		c[i]=a[i]+b[i];
	for(i=1;i<c[0];i++)
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	if(c[c[0]]>=10)
	{
		c[c[0]+1]=c[c[0]]/10;
		c[0]++;
	}
}

void subtract(int a[],int b[],int c[])
{
	int i;
	c[0]=max(a[0],b[0]);
	for(i=1;i<=c[0];i++)
		c[i]=a[i]-b[i];
	for(i=1;i<c[0];i++)
	{
		if(c[i]<0)
		{
			c[i+1]--;
			c[i]+=10;
		}
	}
	while(c[c[0]]==0)
		c[0]--;
}

void multipy(int a[],int b[],int c[])
{
	int i,j;
	c[0]=a[0]+b[0];
	for(i=1;i<=a[0];i++)
		for(j=1;j<=b[0];j++)
			c[i+j-1]+=b[j]*a[i];
	for(i=1;i<=c[0];i++)
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	if(c[c[0]]==0)
		c[0]--;
}

bool judge(int d[],int b[],int x,int c[])
{
	int i,f[MAX];
	if(d[0]<b[0])
		return false;
	for(i=d[0];i>0;i--)
	{
		if(d[i]>b[i])
		{
			memcpy(f,d,sizeof(d));
			subtract(d,b,f);
			memcpy(d,f,sizeof(f));
			c[x]++;
			return true;
		}
		if(d[i]<b[i])
			return false;
	}
	return false;
}

void move(int d[],int a[],int x,int c[])
{
	int i;
	d[0]++;
	for(i=d[0];i>1;i--)
		d[i]=d[i-1];
	d[1]=a[x];
}
void divide(int a[],int b[],int d[],int c[])	
{
	int i;
	d[0]=0;
	for(i=a[0];i>0;i--)
	{
		move(d,a,i,c);
		while(judge(d,b,i,c))
			if(c[0]<i)
				c[0]=i;
	}
}


int main()
{
	freopen ("input.txt","r",stdin);
	int i,a[MAX],b[MAX],la,lb,d[MAX],c[MAX];
	scanf("%s%s",aa,bb);
	la=strlen(aa);
	lb=strlen(bb);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	a[0]=la;
	b[0]=lb;
	for(i=1;i<=a[0];i++)
		a[i]=aa[a[0]-i]-'0';
	for(i=1;i<=b[0];i++)
		b[i]=bb[b[0]-i]-'0';
	memset(c,0,sizeof(c));
	add(a,b,c);
	printf("%s\n%s\nA D D   :  ",aa,bb);
	for(i=c[0];i>0;i--)
		printf("%d",c[i]);
	memset(c,0,sizeof(c));
	subtract(a,b,c);
	printf("\nSUBTRACT:  ");
	for(i=c[0];i>0;i--)
		printf("%d",c[i]);
	memset(c,0,sizeof(c));
	multipy(a,b,c);
	printf("\nMULTIPLY:  ");
	for(i=c[0];i>0;i--)
		printf("%d",c[i]);
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	divide(a,b,d,c);
	printf("\nDIVIDE  :  ");
	for(i=c[0];i>0;i--)
		printf("%d",c[i]);
	printf("\n        MOD:  ");
	for(i=d[0];i>0;i--)
		printf("%d",d[i]);
	printf("\n");
	return 0;
}