#include <iostream>
using namespace std;
#define MAX 20
int a[MAX][2],p,tt;
int dosth(int t)
{
	int i,q=0;
	if(t==0)
		return t;
	if(tt==1)
		return tt;
	for(i=0;i<MAX;i++)
	{
		if(a[i][0]>0&&a[i][1]==0)
			q++;
		if(a[i][1]>1)
			return 1;
	}
	if(q>1||q==0)
		return 1;
	return 0;
}
int main()
{
	int i,j,t;
	p=tt=t=0;
	for(i=0;i<MAX;i++)
		a[i][0]=a[i][1]=0;
	while(cin>>i>>j&&i!=-1&&j!=-1)
	{
		if(i==j&&j==0)
		{
			p++;
			if(dosth(t)==1)
				cout<<"Case "<<p<<" is not a tree.\n";
			else
				cout<<"Case "<<p<<" is a tree.\n";
			t=tt=0;
			for(i=0;i<MAX;i++)
				a[i][0]=a[i][1]=0;
			continue;
		}
		t++;
		if(i==j)
			tt=1;
		a[i-1][0]++;
		a[j-1][1]++;
	}
	return 0;
}
	
		

		

