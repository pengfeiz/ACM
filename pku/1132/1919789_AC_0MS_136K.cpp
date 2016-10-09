#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define MAX 32
int main()
{
	int i,nn,yx[MAX][MAX],x,y,j,k,l,t=0;
	char *s;
	s=(char *)malloc(5000*sizeof(char));
	cin>>nn;
	for(i=0;i<nn;i++)
	{
		t++;
		for(j=0;j<32;j++)
			for(k=0;k<32;k++)
				yx[j][k]=0;
		cin>>x>>y;
		cin>>s;
		l=strlen(s);
		for(j=0;j<l;j++)
		{
			if(*(s+j)=='E')
			{
				yx[y-1][x]=1;
				x++;
			}
			else if(*(s+j)=='W')
			{
				yx[y][x-1]=1;
				x--;
			}
			else if(*(s+j)=='N')
			{
				yx[y][x]=1;
				y++;
			}
			else if(*(s+j)=='S')
			{
				yx[y-1][x-1]=1;
				y--;
			}
		}
		cout<<"Bitmap #"<<t<<endl;
		for(j=31;j>=0;j--)
		{
			for(k=0;k<32;k++)
			{
				if(yx[j][k]==0)
					cout<<'.';
				else
					cout<<'X';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
