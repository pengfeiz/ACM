#include <stdio.h>
#include <iostream.h>
#include <string.h>
#include <stdlib.h>
#include <fstream.h>
#define MAX 100

struct gao
{
	int p;
	int q;
	struct gao *next;
	struct gao *before;
};

struct queue
{
	struct gao *first;
	struct gao *last;
};

void find(int *max,int a[MAX][MAX],int *p,int *q,int m,int n,struct queue *Q,int *zhi)
{
	int i,j,t;
	i=j=t=0;
	while(*p!=m)
	{
		while(a[*p][*q]==2)
		{
			(*q)++;
			if(*q==n)
			{
				(*p)++;
				*q=0;
			}
		}
		if(*p==m)
			break;
		if(a[*p][*q]==0)
		{
			t=0;
			i=*p;
			j=*q;
			while(j>0)
			{				
				j--;
				if(a[i][j]==2)
				{
					t=0;
					break;
				}
				else if(a[i][j]==1)
				{
					t=1;
					break;
				}
			}
			if(t==0)
			{
				j=*q;
				while(i>0)
				{
					i--;
					if(a[i][j]==2)
					{
						t=0;
						break;
					}
					else if(a[i][j]==1)
					{
						t=1;
						break;
					}
				}
			}
		}
		if(t==0)
		{
			a[*p][*q]=1;
			if(Q->first==NULL)
			{
				Q->first=Q->last=(struct gao *)malloc(sizeof(struct gao));
				Q->last->next=NULL;
				Q->last->p=*p;
				Q->last->q=*q;
				Q->last->before=NULL;
			}
			else
			{
				Q->last->next=(struct gao *)malloc(sizeof(struct gao));
				Q->last->next->before=Q->last;
				Q->last=Q->last->next;
				Q->last->next=NULL;
				Q->last->p=*p;
				Q->last->q=*q;
			}
			(*zhi)++;
			(*q)++;
		}
		else if(t==1)
		{
			(*q)++;
		}
		if(*q==n)
		{
			*q=0;
			(*p)++;
		}
	}
	if(*zhi>*max)
		*max=*zhi;
}

int main()
{
	int i,j,*p,*q,m,n,*zhi,*max,a[MAX][MAX];
	struct queue *Q;
	char c;
	Q=(struct queue *)malloc(sizeof(struct queue));
	zhi=(int *)malloc(sizeof(int));
	max=(int *)malloc(sizeof(int));
	p=(int *)malloc(sizeof(int));
	q=(int *)malloc(sizeof(int));
	Q->first=Q->last=NULL;
	while(cin>>n&&n)
	{
		m=n;
		for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
				a[i][j]=0;		
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>c;				
				if(c=='X')
					a[i][j]=2;
				else
					a[i][j]=0;
			}
		}
		*zhi=*max=*p=*q=0;
		find(max,a,p,q,m,n,Q,zhi);
		while(Q->last!=NULL)
		{
			*p=Q->last->p;
			*q=Q->last->q;		
			if(Q->last->before==NULL)
			Q->last=Q->first=NULL;	
			else
			{
				Q->last->before->next=NULL;
				Q->last=Q->last->before;
			}
			a[*p][*q]=0;
			(*zhi)--;
			(*q)++;
			if(*q==n)
			{
				*q=0;
				(*p)++;
			}
			find(max,a,p,q,m,n,Q,zhi);
		}
		cout<<*max<<endl;
	}
	return 0;
}






