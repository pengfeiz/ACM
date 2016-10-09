#include <iostream>
#include <string.h>
using namespace std;
int num[200][200];
int main()
{
	char s[10];
	int nn,x,y,l,i,j,tt;
	cin>>nn;
	for(i=0;i<200;i++)
		for(j=0;j<200;j++)
			num[i][j]=0;
	while(nn-->0)
	{
		cin>>s>>x>>y>>l;
		if(strcmp(s,"BLACK")==0)
		{
			for(i=x;i<x+l;i++)
				for(j=y;j<y+l;j++)
					num[i][j]=1;
		}
		else if(strcmp(s,"WHITE")==0)
		{
			for(i=x;i<x+l;i++)
				for(j=y;j<y+l;j++)
					num[i][j]=0;
		}
		else
		{
			tt=0;
			for(i=x;i<x+l;i++)
				for(j=y;j<y+l;j++)
					if(num[i][j]==1)
						tt++;
			cout<<tt<<endl;
		}
	}
	return 0;
}

