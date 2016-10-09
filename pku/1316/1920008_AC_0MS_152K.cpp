#include <iostream>
#define MAX 10000
using namespace std;
int st[MAX+1000];
int sum(int n)
{
	int m,q;
	m=q=n;
	while(1)
	{
		if(q/10!=0)
		{
			m+=q%10;
			q=q/10;
		}
		else
		{
			m+=q;
			return m;
		}
	}
}
int main()
{
	int i,p;
	for(i=0;i<MAX+1000;i++)
		st[i]=0;
	for(i=0;i<MAX;i++)
	{
		p=sum(i+1);
		st[p-1]=1;
	}
	for(i=0;i<MAX;i++)
		if(st[i]==0)
			cout<<i+1<<endl;
	return 0;
}
