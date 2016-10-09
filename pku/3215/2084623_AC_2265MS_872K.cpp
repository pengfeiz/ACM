#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

double y[MAX];

bool com(double a,double b)
{
	return a<b;
}

int main()
{
	int n,i,p1,p2,t,q;
	double a,b;
	while(scanf("%d",&n)&&n)
	{
		t=p1=p2=q=0;
		for(i=0;i<n-t;i++)
		{
			scanf("%lf%lf",&a,&b);
			if(b==0)
			{
				if(a==0)
				{
					t=1;
					i--;
				}
				else if(a>0)
				{
					p1++;
					y[i]=-999999999999;
				}
				else
				{
					p2++;
					y[i]=999999999999;
				}
			}
			else
			{
				q++;
				y[i]=(-1)*a/b;
			}
		}
		if(t&&p1+p2==n-1)
		{
			if(p1==p2)
				printf("(-inf,+inf)\n");
			else
				printf("-1\n");
			continue;
		}
		if(p1+p2==n)
		{
			printf("-1\n");
			continue;
		}
		sort(y,y+n-t,com);
		if(!t)
		{
			if(y[n/2]==999999999999||y[n/2]==-999999999999)
				printf("-1\n");
			else if(y[n/2]<0&&y[n/2]>-0.005)
				printf("[0.00,0.00]\n");
			else
				printf("[%.2lf,%.2lf]\n",y[n/2],y[n/2]);
			continue;
		}
		if(y[n/2-1]==-999999999999&&y[n/2]==999999999999)
			printf("(-inf,+inf)\n");
		else if(y[n/2-1]==-999999999999&&y[n/2-1]==y[n/2])
			printf("-1\n");
		else if(y[n/2-1]==-999999999999)
		{
			if(y[n/2-1]<0&&y[n/2-1]>-0.005)
				printf("(-inf,0.00]\n");
			else
				printf("(-inf,%.2lf]\n",y[n/2]);
		}
		else if(y[n/2]==999999999999&&y[n/2]==y[n/2-1])
			printf("-1\n");
		else if(y[n/2]==999999999999)
		{
			if(y[n/2]<0&&y[n/2]>-0.005)
				printf("[0.00,+inf)\n");
			else
				printf("[%.2lf,+inf)\n",y[n/2-1]);
		}
		else
		{
			if(y[n/2-1]<0&&y[n/2-1]>-0.005)
				printf("[0.00,");
			else
				printf("[%.2lf,",y[n/2-1]);
			if(y[n/2]<0&&y[n/2]>-0.005)
				printf("0.00]\n");
			else
				printf("%.2lf]\n",y[n/2]);
		}
	}
	return 0;
}

		 
			








