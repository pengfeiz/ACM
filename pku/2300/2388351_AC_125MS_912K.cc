#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2000000

struct gao
{
    int a, win; 
    double p;
}p1[MAX],p2[MAX];

bool com(gao a,gao b)
{
    if(a.a!=b.a)
		return a.a>b.a;
	return a.win>b.win;
}

int x[11]={1,2,4,8,16,32,64,128,256,512,1024};
int m,l,n1,n2,n3,bet;
double prob, sumprob;

int main()
{
	int i,j,k,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&k,&m,&l);
		n1=1;
		p1[0].win=0;
		p1[0].a=0;
		p1[0].p=1;
		prob=1;
		for(i=1;i<=m;i++)
		{
			n2=0;
			for(j=0;j<n1;j++)
			{
				bet=x[p1[j].a];
				// lose 10/14 of the time
				p2[n2].a=bet*2<=l?p1[j].a+1:0;
				p2[n2].win=p1[j].win-bet;
				p2[n2++].p=p1[j].p*10/14;
				// win 1 (2 cases)
				p2[n2].a=0;
				p2[n2].win=p1[j].win + bet;
				p2[n2++].p=p1[j].p * 2/14;
				// win 2
				p2[n2].a=0;
				p2[n2].win=p1[j].win + bet * 2;
				p2[n2++].p=p1[j].p * 1/14;
				// win 3
				p2[n2].a=0;
				p2[n2].win=p1[j].win + bet * 3;
				p2[n2++].p=p1[j].p * 1/14;
			}
			sort(p2,p2+n2,com);
			n1=0;
			sumprob=0;
			for(j=0;j<n2;)
			{
				p1[n1].win=p2[j].win;
				p1[n1].a=p2[j].a;
				p1[n1].p=p2[j].p;
				j++;
				for(;p2[j].win==p1[n1].win&&p1[n1].a==p2[j].a;j++)
					p1[n1].p+=p2[j].p;
				if(p1[n1].win<=0||i<k)
				{
					sumprob+=p1[n1].p;
					n1++; 
				}
			}
			for(j=0;j<n1;j++)
				p1[j].p/=sumprob;
			if(i>=k)
				prob*=sumprob;
		}
		printf("%0.4lf\n",1-prob);
	}
	return 0;
}
