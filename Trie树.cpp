//字典树(大写字母)

#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define MAX 1002

struct gao
{
	//变量
	char c;
	struct gao *a[26];
}*p,*q;

char s[MAX][MAX];
int n;

void find(int x,int l,int ll)
{
	int i=s[x][l]-'A';
	if(l==ll)
		return;
	q=q->a[i];
	find(x,l+1,ll);
}

//在这里修改
void change()
{;}
void build(int x,int l,int ll)
{
	if(l==ll)
		return;
	int i=s[x][l]-'A',j;
	if(q->a[i]==NULL)
	{
		q->a[i]=(struct gao *)malloc(sizeof(struct gao));
		q=q->a[i];
		for(j=0;j<26;j++)
			q->a[j]=NULL;
	}
	else
		q=q->a[i];
	build(x,l+1,ll);
}

int main()
{
	int i,ll;
	scanf("%d",&n);
	memset(s,0,sizeof(s));
	p=(struct gao *)malloc(sizeof(struct gao));
	for(i=0;i<26;i++)
		p->a[i]=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		ll=strlen(s[i]);
		q=p;
		build(i,0,ll);
	}
	change();
	for(i=0;i<n;i++)
	{
		ll=strlen(s[i]);
		q=p;
		find(i,0,ll);
	}
	return 0;
}

