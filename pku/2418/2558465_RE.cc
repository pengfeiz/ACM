#include <iostream>
#include <stdlib.h>
using namespace std;

struct gao
{
	int n;
	struct gao *a[53];
}*p;

char s[32];
int h,l,t;


void build(struct gao *p)
{
	if(h==l)
	{
		p->n++;
		return;
	}
	int q,i;
	if(s[h]==' ')
		q=52;
	else if(s[h]>='a'&&s[h]<='z')
		q=s[h]-'a';
	else
		q=s[h]-'A'+26;
	if(p->a[q]==NULL)
	{
		p->a[q]=(struct gao *)malloc(sizeof(struct gao));
		p=p->a[q];
		p->n=0;
		for(i=0;i<53;i++)
		{
//			p->a[i]=(struct gao *)malloc(sizeof(struct gao));
//			p->n=0;
			p->a[i]=NULL;
		}

	}
	else
		p=p->a[q];
	h++;
	build(p);
}


void out(struct gao *p,int l)
{
	int i;
	if(p->n)
	{
		s[l]='\0';
		printf("%s %.4lf\n",s,(p->n*100.0)/(1.0*t));
	}
	for(i=0;i<53;i++)
		if(p->a[i])
		{
			if(i<26)
				s[l]='a'+i;
			else if(i<52)
				s[l]='A'+i-26;
			else
				s[l]=' ';
			out(p->a[i],l+1);
		}
}


int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	p=(struct gao *)malloc(sizeof(struct gao));
	p->n=0;
	for(i=0;i<53;i++)
	{
//		p->a[i]=(struct gao *)malloc(sizeof(struct gao));
		p->a[i]=NULL;
//		p->n=0;
	}
	t=0;
	while(gets(s))
	{
		t++;
		l=strlen(s);
		h=0;
		build(p);
	}
	out(p,0);
	return 0;
}

	