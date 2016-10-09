#include <iostream>
#include <algorithm>
using namespace std;
int a[20],x,n;
bool b[20];

bool com(int aa,int bb)
{ 
	return aa>bb;
}

bool dosth(int k,int l,int m)
{
	int t=0,i;
	if(k==4)
		return true;
	if(!m)
		return dosth(k+1,0,x);
	if(!b[0])
		t=1;
	for(i=l;i<n;i++)
	{
		if(!b[i]&&a[i]<=m)
		{
			b[i]=true;
			if(dosth(k,i+1,m-a[i]))
				return true;
			b[i]=false;
		}
		while(a[i]==a[i+1]&&b[i+1])
			i++;
		if(t)
			return false;
	}
	return false;
}
int main()
{
	int i,t,k;
	scanf("%d",&k);
	while(k-->0)
	{
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		t=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			t+=a[i];
		}
		if(t%4)
		{
			printf("no\n");
			continue;
		}
		x=t/4;
		sort(a,a+n,com);
		if(dosth(1,0,x))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}

