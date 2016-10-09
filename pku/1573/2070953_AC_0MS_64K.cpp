#include <iostream>
using namespace std;
char a[10][10];
int b[10][10];
int q,x,n,m;
bool dosth(int y,int z)
{
	if(a[y][z]=='N')
	{
		if(y==0)
		{
			q=b[y][z];
			return true;
		}
		else if(b[y-1][z])
		{
			q=b[y][z];
			x=b[y-1][z];
			return false;
		}
		else
		{
			b[y-1][z]=b[y][z]+1;
			return dosth(y-1,z);
		}
	}
	if(a[y][z]=='S')
	{
		if(y==n-1)
		{
			q=b[y][z];
			return true;
		}
		else if(b[y+1][z])
		{
			q=b[y][z];
			x=b[y+1][z];
			return false;
		}
		else
		{
			b[y+1][z]=b[y][z]+1;
			return dosth(y+1,z);
		}
	}
	if(a[y][z]=='W')
	{
		if(z==0)
		{
			q=b[y][z];
			return true;
		}
		else if(b[y][z-1])
		{
			q=b[y][z];
			x=b[y][z-1];
			return false;
		}
		else
		{
			b[y][z-1]=b[y][z]+1;
			return dosth(y,z-1);
		}
	}
	if(a[y][z]=='E')
	{
		if(z==m-1)
		{
			q=b[y][z];
			return true;
		}
		else if(b[y][z+1])
		{
			q=b[y][z];
			x=b[y][z+1];
			return false;
		}
		else
		{
			b[y][z+1]=b[y][z]+1;
			return dosth(y,z+1);
		}
	}
	return false;
}
	
int main()
{
	int i,j,p;
	while(scanf("%d%d%d",&n,&m,&p)&&(n||p||m))
	{
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>a[i][j];
		memset(b,0,sizeof(b));
		b[0][p-1]=1;
		if(dosth(0,p-1))
			printf("%d step(s) to exit\n",q);
		else
		{
			x--;
			printf("%d step(s) before a loop of %d step(s)\n",x,q-x);
		}
	}
	return 0;
}
		
		
