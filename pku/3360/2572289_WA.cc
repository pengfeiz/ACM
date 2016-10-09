#include <iostream>
using namespace std;

int a[1024];
bool b[1024];
int root[1024];

int getroot(int x)
{
	if(root[x]!=x)
		root[x]=getroot(root[x]);
	return root[x];
}

int main()
{
//	freopen("in.txt","r",stdin);
	char ss[100];
	int i,l,x,y;
	int p,q;
	while(scanf("%s",ss)!=EOF)
	{
		memset(b,0,sizeof(b));
		scanf("%s",ss);
		scanf("%s",ss);
		p=q=0;
		memset(a,0,sizeof(a));
		while(scanf("%s",ss),strcmp(ss,"}"))
			b[ss[0]+512]=true;
		while(scanf("%s",ss),strcmp(ss,"{"))
			;
		for(i=0;i<1024;i++)
			root[i]=i;
		while(scanf("%s",ss))
		{
			l=strlen(ss);
			if(l==1)
				break;
			a[ss[1]+512]++;
			x=getroot(ss[1]+512);
			a[ss[3]+512]++;
			y=getroot(ss[3]+512);
			root[x]=y;
			if(l==5)
				break;
		}
		scanf("%s",ss);
		for(i=0;i<1024;i++)
		{
			x=getroot(i);
			if(a[i]&&x==i)
				break;
		}
		for(i=0;i<1024;i++)
			if(a[i]&&getroot(i)!=x)
				p=1000;
		for(i=0;i<1024;i++)
		{
			if(a[i])
				q=1;
			if(a[i]&&!b[i])
				p=100;
			if(a[i]&1)
				p++;
		}
		if(p==2)
			printf("YES ");
		else
			printf("NO ");
		if(p==0&&q)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
