#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2500

struct gao
{
	int x,y,n;
}a[MAX];

bool com(gao a,gao b)
{
	return a.n>b.n;
}

int n,m,t;

void dosth()
{
	int i,j,num,time,tt;
	scanf("%d%d%d",&n,&m,&time);
	t=tt=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%d",&num);
			if(num)
			{
				a[t].x=i;
				a[t].y=j;
				a[t].n=num;
				t++;
			}
		}
	sort(a,a+t,com);
	time-=2+a[0].x;
	i=0;
	while(i<t)
	{
		if(time>a[i].x)
		{
			tt+=a[i].n;
			time-=(abs(a[i].x-a[i+1].x)+abs(a[i].y-a[i+1].y))+1;
		}
		else
			break;
		i++;
	}
	printf("%d\n",tt);
}
	
int main()	
{
	int k;
	scanf("%d",&k);
	while(k--)
		dosth();
	return 0;
}

