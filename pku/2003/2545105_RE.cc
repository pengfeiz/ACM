#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct gao
{
	char s[101];
	struct gao *a,*b;
}*p,*q;

char s[101],c[101];


bool change2(gao *q)
{
	gao *w,*he;
	he=q;
	if(strcmp(q->s,s)==0)
	{
		w=q->b;
		while(w!=NULL)
		{
			he=w;
			w=w->a;
		}
		w=(struct gao*)malloc(sizeof(struct gao));
		strcpy(w->s,c);
		if(he==q)
			he->b=w;
		else
			he->a=w;
		w->a=w->b=NULL;
		return true;
	}
	else
	{
		w=q->b;
		while(w!=NULL)
		{
			if(change2(w))
				return true;
			w=w->a;
		}	
	}
	return false;
}


bool change(gao *father,gao *q,int x)
{
	gao *w,*qq=q,*hf,*hl;
	if(strcmp(qq->s,s)==0)
	{
		hl=qq->a;
		if(x)
			father->a=qq->b;
		else
			father->b=qq->b;
		hf=qq->b;
		while(qq->b!=NULL)
		{
			w=hf->a;
			hf->a=hl;
			qq=qq->b;
			hl=w;
			hf=qq->b;
		}
		qq->b=w;
		return true;
	}
	else
	{
		w=qq->b;
		hf=qq;
		while(w!=NULL)
		{
			if(w==qq->b)
			{
				if(change(hf,w,0))
					return true;
			}
			else if(change(hf,w,1))
				return true;
			hf=w;
			w=w->a;
		}
	}
	return false;
}


void printff(gao *q,int x)
{
	int i;
	gao *w;
	for(i=0;i<x;i++)
		printf("+");
	printf("%s\n",q->s);
	w=q->b;
	while(w!=NULL)
	{
		printff(w,x+1);
		w=w->a;
	}
}

int main()
{
	scanf("%s",s);
	gao *father;
	father=(struct gao*)malloc(sizeof(struct gao));
	p=(struct gao*)malloc(sizeof(struct gao));
	q=p;
	father->b=p;
	strcpy(p->s,s);
	p->a=p->b=NULL;
	while(scanf("%s",s)!=EOF)
	{
		if(strcmp(s,"print")==0)
		{		
			printff(p,0);
			printf("------------------------------------------------------------\n");
		}
		else if(strcmp(s,"fire")==0)
		{
			scanf("%s",s);
			q=p;
			change(father,q,0);
			p=father->b;
		}
		else
		{
			scanf("%s",c);
			scanf("%s",c);
			q=p;
			change2(q);
		}
	}
	return 0;
}

