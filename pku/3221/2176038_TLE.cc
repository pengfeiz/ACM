#include <iostream>
#include <math.h>
using namespace std;
#define MA 10000000

int c[5000],d[5000],a[MA],xx[7][7]={0,0,1,0,1,0,1,0,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,1,0};
int n,x;

int main()
{
	char s[7];
	int i,l,b[7],w,t,j,p;
	for(i=0;i<MA;i++)
		a[i]=-1;
	c[0]=1;
	c[1]=123456;
	l=p=0;
	while(c[0])
	{
		memset(d,0,sizeof(d));
		for(i=1;i<=c[0];i++)
			a[c[i]]=l;
		d[0]=0;
		for(i=1;i<=c[0];i++)
		{
			w=c[i];
			for(j=0;j<7;j++)
			{
				b[j]=w%10;
				if(b[j]==0)
					t=j;
				w/=10;
			}
			for(j=0;j<7;j++)
			{
				w=c[i];
				if(xx[6-t][6-j])
				{
					w-=pow(10,j)*b[j];
					w+=pow(10,t)*b[j];
					if(a[w]<0)
					{
						p++;
						d[0]++;
						d[d[0]]=w;
					}
				}
			}
		}
		memcpy(c,d,sizeof(d));
		l++;
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		x=0;
		for(i=0;i<7;i++)
			x=x*10+s[i]-'0';
		printf("%d\n",a[x]);
	}
	return 0;
}