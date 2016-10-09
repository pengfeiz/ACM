#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000
char s[MAX][11];
int c[26],d[27],n,m,k,minn=0,da[26];
__int64 b[MAX];
bool com(__int64 a1,__int64 a2)
{
	return a1<a2;
}
void dosth(int x,int y)
{
	int i=0,j,t=1,f=0;
	if(x==0)
	{
		da[0]=y;
		c[0]=1;
		da[0]--;
		j=0;
		while(i++<m)
		{
			if(!da[j])
				j++;
			c[i]=j+1;
			da[j]--;
		}
		memset(b,0,sizeof(b));
		for(i=0;i<k;i++)
			for(j=0;j<strlen(s[i]);j++)
				b[i]=b[i]*10+c[s[i][j]-'A'];
		sort(b,b+k,com);
		for(i=0;i<k-1;i++)
		{
			if(b[i]!=b[i+1])
				t++;
			else
			{
				while(b[i]==b[i+1])
					i++;
			}
		}
		if(t>minn)
		{
			minn=t;
			memcpy(d,c,sizeof(c));
		}
		return;
	}
	for(i=0;i<=y;i++)
	{
		da[x]=i;
		dosth(x-1,y-i);
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	memset(c,0,sizeof(c));
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<k;i++)
		scanf("%s",s[i]);
	dosth(n-1,m);
	printf("%d\n",minn);
	d[m]=0;
	for(i=0;i<m;i++)
	{
		if(d[i]==d[i+1])
			printf("%c",i+'A');
		else
			printf("%c\n",i+'A');
	}
	while(d[m-1]++<n)
		printf("\n");
	return 0;
}
