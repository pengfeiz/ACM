#include <iostream>
using namespace std;

bool a[5][5];
int b[5][5];
int c[75];

bool judge()
{
	int i,j;
	bool f;
	for(i=0;i<5;i++)
	{
		f=true;
		for(j=0;j<5;j++)
			if(!a[i][j])
				f=false;
		if(f)
			return true;
	}
	for(i=0;i<5;i++)
	{
		f=true;
		for(j=0;j<5;j++)
			if(!a[j][i])
				f=false;
		if(f)
			return true;
	}
	f=true;
	for(i=0;i<5;i++)
		if(!a[i][i])
			f=false;
	if(f)
		return true;
	f=true;
	for(i=0;i<5;i++)
		if(!a[i][4-i])
			f=false;
	if(f)
		return true;
	return false;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		a[2][2]=true;
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
			{
				if(i==2&&j==2)
					continue;
				scanf("%d",&b[i][j]);
			}
		b[2][2]=-1;
		for(i=0;i<75;i++)
			scanf("%d",&c[i]);
		for(i=0;i<75;i++)
		{
			for(j=0;j<5;j++)
			{
				for(k=0;k<5;k++)
					if(b[j][k]==c[i])
					{
						a[j][k]=true;
						break;
					}
				if(k<5)
					break;
			}
			if(judge())
				break;
		}
		printf("BINGO after %d numbers announced\n",i+1);
	}
	return 0;
}