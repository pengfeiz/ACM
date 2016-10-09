#include <iostream>
using namespace std;

int a[6],b[13],c[13],n;
int d[128],e[128],tt[128];


void init()
{
	int i,j,k,num=n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++)
		d[i]=i;
	for(i=1;i<=1440;i++)
	{
		if(a[0]<4)
		{
			a[0]++;
			a[a[0]]=d[num];
			num--;
		}
		else
		{
			a[0]=0;
			for(j=num;j>0;j--)
				d[j+4]=d[j];
			num+=4;
			for(j=1;j<=4;j++)
				d[j]=a[j];
			if(b[0]<11)
			{
				b[0]++;
				b[b[0]]=d[num];
				num--;
			}
			else
			{
				b[0]=0;
				for(k=num;k>0;k--)
					d[k+11]=d[k];
				num+=11;
				for(k=1;k<=11;k++)
					d[k]=b[k];
				c[0]++;
				c[c[0]]=d[num];
				num--;
				if(c[0]==12)
				{
					c[0]=0;
					for(k=num;k>0;k--)
						d[k+12]=d[k];
					num+=12;
					for(k=1;k<=11;k++)
						d[k+1]=c[k];
					d[1]=c[12];
				}
			}
		}
	}
}


int gcd(int a,int b)
{
	int c;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int find()
{
	int t,i,j;
	for(i=1;i<=n;i++)
		e[d[i]]=i;
	for(i=1;i<=n;i++)
	{
		t=0;
		j=i;
		do
		{
			j=e[j];
			t++;
		}while(j!=i);
		tt[i]=t;
	}
	t=1;
	for(i=1;i<=n;i++)
		t=t*tt[i]/gcd(t,tt[i]);
	return t;
}


int main()
{
	while(scanf("%d",&n),n)
	{
		init();
		printf("%d balls cycle after %d days.\n",n,find());
	}
	return 0;
}