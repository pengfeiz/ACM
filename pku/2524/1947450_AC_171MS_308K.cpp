#include <iostream>
using namespace std;
#define MAX 500001
long a[MAX];
long find(int x)
{
	int p,t;
	p=x;
	while(p!=a[p])
		p=a[p];
	while(x!=p)
	{
		t=a[x];
		a[x]=p;
		x=t;
	}
	return p;
}		
int main()
{
	long n,m,k=0,x,y,i,sum;
	while(scanf("%ld%ld",&n,&m)&&(n||m))
	{
		sum=n;
		for(i=1;i<=n;i++)
			a[i]=i;
		k++;
		cout<<"Case "<<k<<": ";
		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&x,&y);
			if(a[x]!=a[y])
			{
				x=find(x);
				y=find(y);
				if(x!=y)
				{
					if(x>y)
						a[x]=y;
					else if(x<y)
						a[y]=x;
					sum--;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}


