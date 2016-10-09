#include <iostream>
#include <math.h>
#include <string.h>
#define MAX 1000
using namespace std;
long a[1229];
int b[1229];
void jian(long q[MAX])
{
	int i=1;
	while(q[i]==0)
	{
		q[i]=9;
		i++;
	}
	q[i]--;
	if(q[q[0]]==0)
		q[0]--;
}
void cheng(long q[MAX],long x)
{
	int i;
	for(i=1;i<=q[0];i++)
		q[i]*=x;
	for(i=1;i<q[0];i++)
	{
		q[i+1]+=q[i]/10;
		q[i]%=10;
	}
	while(q[q[0]]>9)
	{
		q[0]++;
		q[q[0]]=q[q[0]-1]/10;
		q[q[0]-1]%=10;
	}
}
int prime(long x)
{
	long i;
	for(i=2;i<=(long)sqrt((double)x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
void cheng2(long t[MAX],long q[MAX]) 
{
	int i,j;
	long f[MAX];
	for(i=0;i<=t[0];i++)
		f[i]=t[i];
	memset(t,0,MAX);
	for(i=1;i<=q[0];i++)
		for(j=1;j<=f[0];j++)
			t[j+i-1]+=f[j]*q[i];
	t[0]=f[0]+q[0]-1;
	for(i=1;i<=t[0];i++)
	{
		t[i+1]+=t[i]/10;
		t[i]%=10;
	}	
	if(t[t[0]+1]>0)
		t[0]++;
}
int main()
{
	long t[MAX],n,m,i,j,k,q[MAX];
	for(i=2,j=0;i<10000;i++)
		if(prime(i))
			a[j++]=i;
	while(scanf("%ld%ld",&n,&m)!=EOF)
	{
		memset(b,0,1229);
		memset(t,0,MAX);
		k=m;
		for(i=0;a[i]<=k&&i<1229;i++)					
			while(k%a[i]==0)
			{
				k/=a[i];
				b[i]=1;	
			}
		t[0]=1;
		t[1]=1;
		if(k!=1)
		{
			for(i=0;i<n;i++)
				cheng(t,k);
			jian(t);
		}
		k=m/k;
		for(i=0;a[i]<=m&&i<1229;i++)
		{
			if(b[i]==1)
			{
				k/=a[i];
				memset(q,0,MAX);
				q[0]=q[1]=1;
				for(j=0;j<n;j++)
					cheng(q,a[i]);
				jian(q);
				cheng2(t,q);
			}
		}
		if(k>1)
		{
			for(i=0;i<n;i++)
				cheng(t,k);
		}
		for(i=t[0];i>0;i--)
			printf("%ld",t[i]);
		cout<<endl;
	}
	return 0;
}


