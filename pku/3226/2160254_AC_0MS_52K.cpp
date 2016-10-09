#include <iostream>
using namespace std;
#define MAX 30
char s[MAX];
int l,a[200];

void mul(int x)
{
	int i;
	for(i=1;i<=a[0];i++)
		a[i]*=x;
	for(i=1;i<a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(a[a[0]]>9)
	{
		a[a[0]+1]=a[a[0]]/10;
		a[a[0]]%=10;
		a[0]++;
	}
}

void add(int x)
{
	int i;
	a[1]+=x;
	for(i=1;i<a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(a[a[0]]>9)
	{
		a[a[0]+1]=a[a[0]]/10;
		a[a[0]]%=10;
		a[0]++;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,t,j;
	bool b[26];
	while(scanf("%d",&l),l)
	{
		memset(a,0,sizeof(a));
		scanf("%s",s);
		a[0]=1;
		a[1]=0;
		memset(b,0,sizeof(b));
		for(i=0;i<l;i++)
		{
			t=0;
			for(j=0;j<s[i]-'A';j++)
			{
				if(!b[j])
					t++;
			}
			b[s[i]-'A']=true;
			add(t);
			if(i!=l-1)
				mul(25-i);
		}
		for(i=a[0];i>0;i--)
			printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}



