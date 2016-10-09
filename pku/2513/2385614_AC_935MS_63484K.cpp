#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 600001

struct trie
{
	int n,t;
	struct trie *s[26];
}*root;
bool f,dd,xx;

int ro[MAX],t;
char s[15];

void dosth(trie *q)
{
	int i;
	if(!f)
		return;
	if(q->n%2)
	{
		if(dd)
			dd=false;
		else if(xx)
			xx=false;
		else
		{
			f=false;
			return;
		}
	}
	for(i=0;f&&i<26;i++)
		if(q->s[i]!=NULL)
			dosth(q->s[i]);
}

int getroot(int x)
{
	int foot;
	if(x==ro[x])
		return x;
	foot=getroot(ro[x]);
	ro[x]=foot;
	return foot;
}

int main()
{
//	freopen("H.8.dat","r",stdin);
	trie *p;
	int i,j,x,y;
	for(i=0;i<MAX;i++)
		ro[i]=i;
	t=0;
	f=dd=xx=true;
	root=(struct trie *)malloc(sizeof(trie));
	for(i=0;i<26;i++)
		root->s[i]=NULL;
	root->n=root->t=0;
	while(scanf("%s",s)!=EOF)
	{
		p=root;
		i=0;
		while(s[i]!='\0')
		{
			if(p->s[s[i]-'a']==NULL)
			{
				p->s[s[i]-'a']=(struct trie *)malloc(sizeof(trie));
				p=p->s[s[i]-'a'];
				for(j=0;j<26;j++)
					p->s[j]=NULL;
				p->n=p->t=0;
			}
			else
				p=p->s[s[i]-'a'];
			i++;
		}
		p->n++;
		if(!p->t)
		{
			t++;
			p->t=t;
		}
		x=p->t;
		scanf("%s",s);
		p=root;
		i=0;
		while(s[i]!='\0')
		{
			if(p->s[s[i]-'a']==NULL)
			{
				p->s[s[i]-'a']=(struct trie *)malloc(sizeof(trie));
				p=p->s[s[i]-'a'];
				for(j=0;j<26;j++)
					p->s[j]=NULL;
				p->n=p->t=0;
			}
			else
				p=p->s[s[i]-'a'];
			i++;
		}
		p->n++;
		if(!p->t)
		{
			t++;
			p->t=t;
		}
		y=p->t;
		x=getroot(x);
		y=getroot(y);
		ro[y]=x;
	}
	x=getroot(1);
	for(i=2;i<=t;i++)
		if(getroot(i)!=x)
		{
			f=false;
			break;
		}
	dosth(root);
	if(f)
		printf("Possible\n");
	else
		printf("Impossible\n");
	return 0;
}