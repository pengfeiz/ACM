#include <iostream>
using namespace std;
int a[10],n,x;
int cc(int w,int p)
{
	int i,q;
	if(p>w/2)
		p=w-p;
	q=1;
	for(i=0;i<p;i++)
		q*=(w-i)/(i+1);
	return q;
}
int dosth(int i,int xx)
{
	int j;
	for(j=n-1;j>=0;j--)
	{
		if(a[j])
			continue;
		if(i==n-1&&j+1==xx)
		{
			cout<<j+1;
			return 1;
		}
		if(i==n-1)
			return 0;	
		if(a[j]==0&&i!=n-1)
		{
			a[j]=1;
			if(dosth(i+1,xx-(j+1)*cc(n-1,i))==1)
			{
				cout<<" "<<(j+1);
				return 1;
			}
			a[j]=0;
		}
	}
	return 0;
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
		
