#include <iostream>
using namespace std;

struct
{
	bool a[26];
}b[1025];
char s[1025][1001];
int n,l,q,t;

void dosth(int x,int d,int r)
{
	int i,w;
	bool f=false;
	if(d==q)
	{
		b[x].a[s[x][r]-'A']=true;
		return;
	}
	w=2*x;
	dosth(w,d+1,r);
	dosth(w+1,d+1,r);
	for(i=0;i<26;i++)
	{
		if(b[w].a[i]&&b[w+1].a[i])
		{
			f=true;
			break;
		}
	}
	if(f)
	{
		for(i=0;i<26;i++)
		{
			if(b[w].a[i]&&b[w+1].a[i])
				b[x].a[i]=true;
			else
				b[x].a[i]=false;
		}
	}
	else
	{
		t++;
		for(i=0;i<26;i++)
		{
			if(b[w].a[i]||b[w+1].a[i])
				b[x].a[i]=true;
			else
				b[x].a[i]=false;
		}
	}
}
		
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,p;
	while(scanf("%d%d",&n,&l),n||l)
	{
		p=n;
		q=t=0;
		while(p)
		{
			q++;
			p>>=1;
		}
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		for(i=0;i<l;i++)
		{
			memset(b,0,sizeof(b));
			dosth(0,1,i);
			for(j=0;j<26;j++)
				if(b[0].a[j])
				{
					printf("%c",j+'A');
					break;
				}
		}
		printf(" %d\n",t);
	}
	return 0;
}
