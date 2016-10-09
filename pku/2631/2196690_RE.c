#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gao
{
	int to,l;
	struct gao *next;
}Node;

#define MAXV 6

Node *d[MAXV];
int V[MAXV];
int vr,max;

void dfs(int v,int len) 
{
	Node *n;
	V[v] = 1;
	if(len>max) 
	{
		max=len;
		vr=v;
	}
	n=d[v];
	while(n)
	{
		if(!V[n->to])
			dfs(n->to,len+n->l);
		n=n->next;
	}
}

int main() 
{
	int i,from,to,dist;
	Node *newnode;
    for(i=1;i<MAXV;i++) 
	{
		V[i]=0;
		d[i]=NULL;
	}
	while(scanf("%d%d%d",&from,&to,&dist)!=EOF) 
	{
		newnode=(Node *)malloc(sizeof(Node));
		newnode->to=to;
		newnode->l=dist;
		newnode->next=NULL;
		if(d[from]) 
		{
			newnode->next=d[from];
			d[from]=newnode;
		} 
		else
			d[from]=newnode;
		newnode=(Node *)malloc(sizeof(Node));
		newnode->to=from;
		newnode->l=dist;
		newnode->next=NULL;
		if(d[to])
		{
			newnode->next=d[to];
			d[to]=newnode;
		} 
		else
			d[to] = newnode;
	}
	vr=1; 
	max=0;
	dfs(1,0);
	memset(V,0,sizeof(V));
	max=0;
	dfs(vr,0);
	printf("%d\n",max);
	return 0;
}