#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct gao
{
	int n;
	struct gao *next;
};

int main()
{
	int num[1000][1000],n,i,j,no[1000];
	gao *hehe,*p,*q;
	p=(struct gao *)malloc(sizeof(struct gao));
	hehe=(struct gao *)malloc(sizeof(struct gao));
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			no[i]=0;
			for(j=0;j<n;j++)
				scanf("%d",&num[i][j]);
		}
		cout<<"1\n"<<n<<"\n";
		for(i=1;i<n;i++)
			if(num[i][0]==1)
				break;
		if(i!=n)
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
			for(i=1;i<n;i++)
				if(num[0][1]==1)
					break;
			hehe->n=0;
			no[i]=no[0]=1;
			hehe->next=(struct gao *)malloc(sizeof(struct gao));
			p=hehe->next;
			p->n=i;
			p->next=(struct gao *)malloc(sizeof(struct gao));
			p->next=NULL;
		}
		for(i=2;i<n;i++)
		{
			p=hehe;
			if(num[i][hehe->n]==1&&no[i]==0)
			{
				q=(struct gao *)malloc(sizeof(struct gao));
				q->n=i;
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
			if(p->next==NULL)
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
			cout<<p->n+1;
			p=p->next;
		}
		cout<<endl;
	}
	return 0;
}


	


