#include <iostream>
#include <fstream>
using namespace std;
int n;
int dosth(int x,int y,char a[10][10])
{
	int t=0;
	if(x>0&&a[x-1][y]=='*')
		t++;
	if(x>0&&y>0&&a[x-1][y-1]=='*')
		t++;
	if(x>0&&y<n-1&&a[x-1][y+1]=='*')
		t++;
	if(x<n-1&&y>0&&a[x+1][y-1]=='*')
		t++;
	if(x<n-1&&y<n-1&&a[x+1][y+1]=='*')
		t++;
	if(x<n-1&&a[x+1][y]=='*')
		t++;
	if(y<n-1&&a[x][y+1]=='*')
		t++;
	if(y>0&&a[x][y-1]=='*')
		t++;
	return t;
}
int main()
{
	//ifstream cin("input.txt");
	int i,j,t=1;
	char a[10][10],b[10][10];
	int c[10][10];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			c[i][j]=-1;
			if(b[i][j]=='x')
				c[i][j]=1;
		}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(c[i][j]==1)
			{
				if(a[i][j]=='*')
					c[i][j]=t=-1;
				else
					c[i][j]=dosth(i,j,a);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(t==-1&&a[i][j]=='*')
				cout<<"*";
			else if(c[i][j]==-1)
				cout<<".";
			else
				cout<<c[i][j];
		}
		cout<<endl;
	}
	return 0;
}

	