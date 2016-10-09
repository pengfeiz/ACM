#include <iostream>
using namespace std;
#define MAX 20

char s[MAX];
int a[MAX];
char c[MAX][MAX];
int ll[MAX],l,n,t;


int find(int x,int y,int &t)
{
	int num=0;
	t=x;
	while(t<l&&num<ll[y])
	{
		if(c[y][num]==s[t])
		{
			num++;
			t++;
		}
		else
			t++;
	}
	if(num<ll[y])
		return -1;
	return t-x-num;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,q,minn;
	scanf("%d%d",&n,&l);
	scanf("%s",s);
	for(i=0;i<n;i++)
		scanf("%s",c[i]);
	for(i=0;i<=l;i++)
		a[i]=i;
	for(i=0;i<n;i++)
		ll[i]=strlen(c[i]);
	for(i=0;i<l;i++)
		for(j=0;j<n;j++)
		{
			if(s[i]!=c[j][0])
				continue;
			q=find(i,j,t);
			if(q<0)
				continue;
			if(a[t]>a[i]+q)
				a[t]=a[i]+q;
		}
	minn=0x7fffffff;
	for(i=0;i<=l;i++)
		if(minn>a[i]+l-i)
			minn=a[i]+l-i;
	printf("%d\n",minn);
	return 0;
}
