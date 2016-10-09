#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100005
struct gao
{
	int x,y;
}a[MAX];
bool b[MAX];
bool com(gao a,gao b)
{
	if(a.x<b.x)
		return true;
	else if(a.y<b.y)
		return true;
	return false;
}
int main()
{
	int m,n=0,x,y,t=-1,i,j,judge;
	scanf("%d",&m);
	while(scanf("%d%d",&x,&y)&&(x||y))
	{
		a[n].x=x;
		a[n++].y=y;
		if(x<=0&&y>=m)
			t=n-1;
	}
	if(t>=0)
	{
		printf("1\n%d %d\n",a[t].x,a[t].y);
		return 0;
	}
	sort(a,a+n,com);
	memset(b,0,sizeof(b));
	j=t;
	x=y=t=judge=0;
	for(i=0;i<n;i++)
	{
		if(a[i].x>x)
			break;
		while(a[i].x<=x&&i<n)
		{
			if(a[i].y>y)
			{
				y=a[i].y;
				j=i;
			}
			i++;
		}
		x=y;
		b[j]=true;
		t++;
		if(y>=m)
		{
			judge=1;
			break;
		}
		i--;
	}
	if(!judge)
		printf("No solution\n");
	else
	{
		printf("%d\n",t);
		for(i=0;i<n;i++)
			if(b[i])
				printf("%d %d\n",a[i].x,a[i].y);
	}
	return 0;
}
