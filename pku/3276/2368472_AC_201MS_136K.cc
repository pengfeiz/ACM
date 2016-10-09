#include <iostream>
using namespace std;
#define MAX 5002

bool a[MAX],b[MAX];
char s[2],c[2];
int n;

int main()
{
	int i,k,minn,t,q;
	scanf("%d",&n);
	scanf("%s",&c);
	if(c[0]=='B')
		b[0]=true;
	else
		b[0]=false;
	for(i=1;i<n;i++)
	{
		scanf("%s",&s);
		if(s[0]==c[0])
			b[i]=false;
		else
			b[i]=true;
		c[0]=s[0];
	}
	minn=0x7fffffff;
	for(k=1;k<=n;k++)
	{
		t=0;
		memcpy(a,b,sizeof(b));
		for(i=0;i<=n-k;i++)
		{
			if(a[i])
			{
				t++;
				a[i+k]=!a[i+k];
			}
			if(t>minn)
				break;
		}
		for(;i<n;i++)
			if(a[i])
				break;
		if(i==n&&t<minn)
		{
			minn=t;
			q=k;
		}
	}
	printf("%d %d\n",q,minn);
	return 0;
}

