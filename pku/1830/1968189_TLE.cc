#include <iostream>
using namespace std;
int a[29],n,b[29],q[29][29],t;
void dosth(int i)
{
	int j;
	if(i==n)
	{
		for(i=0;i<n;i++)
			if(a[i]%2!=0)
				return;
		t++;
		return;
	}
	else
	{
		a[i]++;
		for(j=0;j<n;j++)
			a[j]+=q[i][j];
		dosth(i+1);
		a[i]--;		
		for(j=0;j<n;j++)
			a[j]-=q[i][j];
		dosth(i+1);
	}
}
int main()
{
	int nn,i,f,g;
	cin>>nn;
	while(nn-->0)
	{
		t=0;
		cin>>n;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(i=0;i<n;i++)
		{
			if(a[i]==b[i])
				a[i]=0;
			else
				a[i]=1;
		}
		memset(q,0,29*29);
		while(scanf("%d%d",&f,&g)&&(f||g))
			q[f-1][g-1]=1;
		dosth(0);
		if(t)
			cout<<t<<endl;
		else
			cout<<"Oh,it's impossible~!!\n";
	}
	return 0;
}
	