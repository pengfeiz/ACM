#include <iostream>
#include <stdlib.h>
using namespace std;


struct trie
{
	int n,m;
	struct trie *s[26];
}*root;
bool f,dd,xx;

char s[11];

void dosth(trie *q)
{
	int i;
	if(!f)
		return;
	if(q->n>q->m)
	{
		if(dd)
			dd=false;
		else
		{
			f=false;
			return;
		}
	}
	if(q->m>q->n)
	{
		if(xx)
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

int main()
{
//	freopen("in.txt","r",stdin);
	trie *p;
	int i,j;
	f=dd=xx=true;
	root=(struct trie *)malloc(sizeof(trie));
	for(i=0;i<26;i++)
		root->s[i]=NULL;
	root->n=root->m=0;
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
				p->n=p->m=0;
			}
			else
				p=p->s[s[i]-'a'];
			i++;
		}
		p->n++;
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
				p->n=p->m=0;
			}
			else
				p=p->s[s[i]-'a'];
			i++;
		}
		p->m++;
	}
	dosth(root);
	if(f)
		printf("Possible\n");
	else
		printf("Impossible\n");
	return 0;
}
	
