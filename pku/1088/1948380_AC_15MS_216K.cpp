#include <iostream>
using namespace std;
int num[100][100],a[100][100]={0},r,c;
int max(int a,int b)
{
	return a>b?a:b;
}
int dosth(int i,int j)
{
	if(a[i][j]>0)
		return a[i][j];
	a[i][j]=0;
	if(i>0&&num[i-1][j]<num[i][j])
	{
		if(a[i-1][j]>0)
			a[i][j]=max(a[i][j],a[i-1][j]+1);
		else
			a[i][j]=max(a[i][j],dosth(i-1,j)+1);
	}
	if(j>0&&num[i][j-1]<num[i][j])
	{
		if(a[i][j-1]>0)
			a[i][j]=max(a[i][j],a[i][j-1]+1);
		else
			a[i][j]=max(a[i][j],dosth(i,j-1)+1);
	}
	if(i<r-1&&num[i+1][j]<num[i][j])
	{
		if(a[i+1][j]>0)
			a[i][j]=max(a[i][j],a[i+1][j]+1);
		else
			a[i][j]=max(a[i][j],dosth(i+1,j)+1);
	}
	if(j<c-1&&num[i][j+1]<num[i][j])
	{
		if(a[i][j+1]>0)
			a[i][j]=max(a[i][j],a[i][j+1]+1);
		else
			a[i][j]=max(a[i][j],dosth(i,j+1)+1);
	}
	return a[i][j];
}
int main()
{
	int i,j,max=0;
	cin>>r>>c;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			scanf("%d",&num[i][j]);
			a[i][j]=-1;
		}
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			a[i][j]=dosth(i,j);
			if(a[i][j]>max)
				max=a[i][j];
		}
	cout<<max+1<<endl;
	return 0;
}


