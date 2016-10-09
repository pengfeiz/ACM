#include <iostream>
using namespace std;


int b[1025];
char s[1025][1001];
int c[26];
int n,l,q,t;

void dosth(int x,int d,int r)
{
	int w=x<<1;
	if(d==q)
	{
		b[x]=c[s[x][r]-'A'];
		return;
	}
	dosth(w,d+1,r);
	dosth(w+1,d+1,r);
	if(b[w]&b[w+1])
		b[x]=b[w]&b[w+1];
	else
	{
		t++;
		b[x]=b[w]|b[w+1];
	}
}
		
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,p;
	for(i=0;i<26;i++)
		c[i]=(1<<i);
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
			for(j=0;j<n;j++)
				b[j]=0;
			dosth(0,1,i);
			for(j=0;j<26;j++)
				if(b[0]&c[j])
				{
					printf("%c",j+'A');
					break;
				}
		}
		printf(" %d\n",t);
	}
	return 0;
}
