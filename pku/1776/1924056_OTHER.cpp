#include <iostream>
#include <math.h>
#include <stdlib.h>
#define MAX 100
using namespace std;

struct gao
{
	int n;
	struct gao *next;
};

int main()
{
	int num[MAX][MAX],n,i,j,no[MAX];
	gao *hehe,*p,*q;
	p=(struct gao *)malloc(sizeof(struct gao));
	hehe=(struct gao *)malloc(sizeof(struct gao));
	while(cin>>n&&n)
	{
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		for(i=0;i<n;i++)
		{
			no[i]=0;
			for(j=0;j<n;j++)
				scanf("%d",&num[i][j]);
		}
		cout<<"1\n"<<n<<"\n";
		for(i=1;i<n;i++)
		{
			if(num[0][i]==1)
				break;
			else if(num[i][0]==1)
				break;
		}
		if(num[i][0]==1)
		{
			hehe->n=i;
			no[i]=no[0]=1;
			hehe->next=(struct gao *)malloc(sizeof(struct gao));
			p=hehe->next;
			p->n=0;
			p->next=(struct gao *)malloc(sizeof(struct gao));
			p->next=NULL;
		}
		else
		{
			hehe->n=0;
			no[i]=no[0]=1;
			hehe->next=(struct gao *)malloc(sizeof(struct gao));
			p=hehe->next;
			p->n=i;
			p->next=(struct gao *)malloc(sizeof(struct gao));
			p->next=NULL;
		}
		for(i=1;i<n;i++)
		{
			p=hehe;
			if(num[i][hehe->n]==1&&no[i]==0)
			{
				q=(struct gao *)malloc(sizeof(struct gao));
				q->n=i;
				no[i]=1;
				q->next=(struct gao *)malloc(sizeof(struct gao));
				q->next=hehe;
				hehe=q;
				continue;
			}
			while(p->next!=NULL)
			{
				if(num[p->n][i]==1&&num[i][p->next->n]==1&&no[i]==0)
				{
					q=(struct gao *)malloc(sizeof(struct gao));
					q->n=i;
					no[i]=1;
					q->next=(struct gao *)malloc(sizeof(struct gao));
					q->next=p->next;
					p->next=q;
					break;
				}
				else
					p=p->next;
			}
			if(p->next==NULL&&no[i]==0)
			{
				q=(struct gao *)malloc(sizeof(struct gao));
				q->next=(struct gao *)malloc(sizeof(struct gao));
				q->next=NULL;
				q->n=i;
				no[i]=1;
				p->next=q;
			}
		}
		p=hehe;
		while(p!=NULL)
		{
			if(p!=hehe)
				cout<<" ";
			cout<<(p->n)+1;
			p=p->next;
		}
		cout<<endl;
	}
	return 0;
}


	


