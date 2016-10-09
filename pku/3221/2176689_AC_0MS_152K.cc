#include <iostream>
#include <math.h>
using namespace std;
#define MA 5040

int c[2800],a[MA],xx[7][4]={3,2,4,6, 2,2,6,0, 3,0,1,3, 2,2,4,0, 3,0,3,5, 2,4,6,0, 3,0,1,5};
int n,x,po[7]={1000000,100000,10000,1000,100,10,1},e[]={1,1,2,6,24,120,720};

int has(int h)
{
	int i,t,ju,j,u=0,b[7];
	for(i=0;i<7;i++)
	{
		b[i]=h%10;
		h/=10;
	}
	bool f[7];
	memset(f,0,sizeof(f));
	for(i=6;i>=0;i--)
	{
		t=b[i];
		ju=0;
		for(j=0;j<t;j++)
		{
			if(f[j])
				continue;
			ju++;
		}
		f[t]=true;
		u+=ju*e[i];
	}
	return u;
}
int main()
{
	char s[7];
	int i,l,b[7],w,t,j,p,q,u;
	memset(a,0,sizeof(a));
	c[0]=p=q=1;
	c[1]=123456;
	l=2;
	a[has(123456)]=1;
	while(p<=q)
	{
		for(i=p;i<=q;i++)
		{
			w=c[i];
			for(j=6;j>=0;j--)
			{
				b[j]=w%10;
				if(b[j]==0)
					t=j;
				w/=10;
			}
			for(j=1;j<=xx[t][0];j++)
			{
				w=c[i];
				w-=po[xx[t][j]]*(b[xx[t][j]]);
				w+=po[t]*(b[xx[t][j]]);
				u=has(w);
				if(!a[u])
				{
					a[u]=l;
					c[0]++;
					c[c[0]]=w;
				}
			}
		}
		p=q+1;
		q=c[0];
		l++;
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		x=atoi(s);
		printf("%d\n",a[has(x)]-1);
	}
	return 0;
}