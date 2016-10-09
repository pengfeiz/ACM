#include <iostream>
using namespace std;
int a[100][100],n,m,t;
void dosth(int i,int j)
{
	if(i>0)
	{
		if(j>0&&a[i-1][j-1]==0)
		{
			a[i-1][j-1]=t;
			dosth(i-1,j-1);
		}
		if(a[i-1][j]==0)
		{
			a[i-1][j]=t;
			dosth(i-1,j);
		}
		if(j<m-1&&a[i-1][j+1]==0)
		{
			a[i-1][j+1]=t;
			dosth(i-1,j+1);
		}
	}
	if(j>0&&a[i][j-1]==0)
	{
		a[i][j-1]=t;
		dosth(i,j-1);
	}
	if(j<m-1&&a[i][j+1]==0)
	{
		a[i][j+1]=t;
		dosth(i,j+1);
	}
	if(i<n-1)
	{
		if(j>0&&a[i+1][j-1]==0)
		{
			a[i+1][j-1]=t;
			dosth(i+1,j-1);
		}
		if(a[i+1][j]==0)
		{
			a[i+1][j]=t;
			dosth(i+1,j);
		}
		if(j<m-1&&a[i+1][j+1]==0)
		{
			a[i+1][j+1]=t;
			dosth(i+1,j+1);
		}
	}
}
int main()
{
	int i,j;
	cin>>n>>m;
	char c;
	t=1;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cin>>c;
			if(c=='W')
				a[i][j]=0;
			else
				a[i][j]=-1;
		}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(a[i][j]==0)
			{
				dosth(i,j);
				t++;
			}
	cout<<t-1<<endl;
	return 0;
}