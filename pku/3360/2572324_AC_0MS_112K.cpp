#include <iostream>
using namespace std;

int a[256];
int root[256];

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
	int p;
	while(scanf("%s",ss)!=EOF)
	{
		scanf("%s",ss);
		scanf("%s",ss);
		p=0;
		memset(a,0,sizeof(a));
		while(scanf("%s",ss),strcmp(ss,"}"));
		while(scanf("%s",ss),strcmp(ss,"{"))
			;
		for(i=0;i<256;i++)
			root[i]=i;
		while(scanf("%s",ss))
		{
			l=strlen(ss);
			if(l==1)
				break;
			a[ss[1]]++;
			x=getroot(ss[1]);
			a[ss[3]]++;
			y=getroot(ss[3]);
			root[x]=y;
			if(l==5)
				break;
		}
		scanf("%s",ss);
		for(i=0;i<256;i++)
		{
			x=getroot(i);
			if(a[i]&&x==i)
				break;
		}
		for(i=0;i<256;i++)
			if(a[i]&&getroot(i)!=x)
				p=1000;
		for(i=0;i<256;i++)
			if(a[i]&1)
				p++;
		if(p==2)
			printf("Yes ");
		else
			printf("No ");
		if(p==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
