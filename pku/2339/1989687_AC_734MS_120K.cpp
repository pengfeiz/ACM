#include <iostream>
using namespace std;
#define MAX 100
char a[MAX][MAX],b[MAX][MAX];
int dosth(char aa,char bb)
{
	if(aa=='S'&&bb=='R')
		return 1;
	if(aa=='P'&&bb=='S')
		return 1;
	if(aa=='R'&&bb=='P')
		return 1;
	return 0;
}
int main()
{
	int r,c,d,n,i,j;
	cin>>n;
	while(n-->0)
	{
		cin>>r>>c>>d;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				cin>>a[i][j];
		while(d-->0)
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					if(i>0)
						if(dosth(a[i][j],a[i-1][j])==1)
						{
							b[i][j]=a[i-1][j];
							continue;
						}
					if(j>0)
						if(dosth(a[i][j],a[i][j-1])==1)
						{
							b[i][j]=a[i][j-1];
							continue;
						}
					if(i<r-1)
						if(dosth(a[i][j],a[i+1][j])==1)
						{
							b[i][j]=a[i+1][j];
							continue;
						}
					if(j<c-1)
						if(dosth(a[i][j],a[i][j+1])==1)
						{
							b[i][j]=a[i][j+1];
							continue;
						}
					b[i][j]=a[i][j];
				}
			}
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					a[i][j]=b[i][j];
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				cout<<a[i][j];
			cout<<endl;
		}
		if(d)
			cout<<endl;
	}
	return 0;
}
