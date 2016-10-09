#include <iostream>
#include <string.h>
using namespace std;
#define MAX 8
int a[MAX][MAX],t,n;
void dosth(int x,int y,int num,int b[])
{

	int i,c[MAX];
	if(num==0)
	{
		t++;
		return;
	}
	memcpy(c,b,sizeof(c));
	if(x==8)
		return;
	if(8-x<num)
		return;
	for(i=y;i<n;i++)
		if(a[x][i]==1&&c[i]==0)
		{
			c[i]=1;
			dosth(x+1,0,num-1,c);
		}
	dosth(x+1,0,num,b);
}
int main()
{
	int i,j,m,b[MAX];
	char c;
	while(cin>>n>>m&&n!=-1&&m!=-1)
	{
		memset(b,0,sizeof(b));
		for(i=t=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				cin>>c;
				if(c=='.')
					a[i][j]=0;
				else
					a[i][j]=1;
			}
		dosth(0,0,m,b);
		cout<<t<<endl;
	}
	return 0;
}

