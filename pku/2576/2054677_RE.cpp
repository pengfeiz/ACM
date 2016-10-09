#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
int p1,p2;
bool com(int a,int b)
{
	return a>b;
}
void dosth(int a[],int n,int t)
{
	int i,j;
	bool c[50][10000];
	memset(c,0,sizeof(c));
	c[0][5000]=true;
	for(i=0;i<n;i+=2)
	{
		for(j=0;j<10000;j++)
			if(c[i/2][j])
			{
				c[i/2+1][j+a[i]-a[i+1]]=true;
				c[i/2+1][j-a[i]+a[i+1]]=true;
			}
	}
	for(j=5000;j<10000;j++)
		if(c[n/2][j])
		{
			p2=(j-5000+t)/2;
			p1=t-p2;
			return;
		}
}
int main()
{	
	int n,i,j,k,a[MAX],b[MAX],l1,l2,min,t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		t+=a[i];
	}
	sort(a,a+n,com);
	if(n%2)
	{
		min=99999999;
		for(i=0;i<n;i++)
		{
			t=0;
			for(k=j=0;k<n;k++)
			{
				if(k==i)
					continue;
				b[j++]=a[k];
				t+=a[k];
			}
			p1=p2=0;
			dosth(b,j,t);
			if(p1>p2)
				p2+=a[i];
			else
				p1+=a[i];
			if(abs(p1-p2)<min)
			{
				min=abs(p1-p2);
				l1=p1;
				l2=p2;
			}
		}
	}
	else
	{
		dosth(a,n,t);
		l1=p1;
		l2=p2;
	}
	if(l1>l2)
		swap(l1,l2);
	printf("%d %d\n",l1,l2);
	return 0;
}




	