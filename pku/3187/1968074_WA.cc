#include <iostream>
using namespace std;
int a[10],n,x,b[10];
int cc(int w,int p)
{
	int i,q;
	if(p>w/2)
		p=w-p;
	q=1;
	for(i=0;i<p;i++)
		q=q*(w-i)/(i+1);
	return q;
}
void dosth(int i,int xx)
{
	int j;

	if (i>=n)
	{
		if(xx==0)
		{
			for (j=0;j<n;j++)
			{
				if(j)
					cout<<" ";
				cout<<b[j];
			}
			

			exit(0);
		}
		return;		
	}

	for(j=1;j<=n;j++)
	{
			if (a[j])continue;
			a[j]=1;
			b[i]=j;
			dosth(i+1,xx-j*cc(n-1,i));			
			a[j]=0;
		
	}
}
int main()
{
	while(cin>>n>>x)
	{
		memset(a,0,sizeof(a));
		dosth(0,x);
		cout<<endl;
	}
	return 0;
}
		
