#include <iostream>
using namespace std;

#define MAX 16

int ee,n,m,tt,let[15]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
double wait[MAX],d[MAX][MAX],a[MAX][1<<MAX],tim;
		
void dp()
{	
	int	i,j,k,s;
	double t,p;
	memset(a,127,sizeof(a));
	a[0][0]=0;
	for(k=0;k<m;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(a[i][k]>999999)
					continue;
				if(k&let[j])
					t=0;
				else
					t=wait[j];
				s=k|let[j];
				p=a[i][k]+d[i][j]+t;
				if(p<a[j][s])
					a[j][s]=p;				
			}
}

void floyd()
{
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
}

void judge()
{
	int num,j,i;
	for(i=0;i<m;i++)
	{	
		if(a[0][i]<=tim&&(ee&i)==ee)
		{
			num=0;
			for(j=0;j<n;j++)
			{
				if(i&let[j])
					num++;
			}
			if(num>tt)
				tt=num;
		}
	}
}

int main()
{
	int i,p,q;
	double l;
	while(scanf("%d%d%lf",&n,&m,&tim),n||m)
	{
		ee=tt=0;
		tim*=12.0;
		memset(d,127,sizeof(d));
		for(i=0;i<m;i++)
		{
			scanf("%d",&p);
			ee=ee|(1<<(p-1));
		}
		ee=ee|1;
		m=(1<<n);
		for(i=0;i<n;i++)
			scanf("%lf",&wait[i]);
		while(scanf("%d%d%lf%d",&p,&q,&l,&i),p||q||(int)l||i)
		{
			if(i)
				l/=120.0;
			else
				l/=80.0;
			p--;
			q--;
			if(l<d[p][q])
				d[p][q]=d[q][p]=l;
		}
		floyd();
		dp();
		judge();
		if(tt)
			printf("%d\n",tt);
		else
			printf("No Solution\n");
	}
	return 0;
}