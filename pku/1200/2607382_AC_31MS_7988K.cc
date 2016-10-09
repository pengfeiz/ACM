#include <iostream>
using namespace std;

bool a[16000001]={0};
char s[1000001];
int n,m;
bool b[26]={0};
int c[26];

int main()
{
	int l,i,p,t,tt,w;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++)
		b[s[i]-'a']=true;
	w=1;
	for(i=t=0;i<26;i++)
		if(b[i])
			c[i]=t++;
	for(i=0;i<n;i++)
		w*=t;
	p=tt=0;
	if(n>l)
	{
		printf("0\n");
		return 0;
	}
	for(i=0;i<n;i++)
		p=p*t+c[s[i]-'a'];
	tt=1;
	a[p]=true;
	for(;i<l;i++)
	{
		p=p*t+c[s[i]-'a'];
		p%=w;
		if(!a[p])
		{
			tt++;
			a[p]=true;
		}
	}
	printf("%d\n",tt);
	return 0;
}