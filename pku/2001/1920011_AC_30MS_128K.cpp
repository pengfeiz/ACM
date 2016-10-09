#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	char s[1000][30];
	int n=0,i,j,k,ii;
	while(cin>>s[n])
		n++;
	for(i=0;i<n;i++)
	{
		cout<<s[i]<<" ";
		k=0;
		for(ii=0;ii<n;ii++)
		{
			if(ii==i)
				continue;
			for(j=0;j<30;j++)
				if(s[i][j]!=s[ii][j])
				{
					if(k<j)
						k=j;
					break;
				}
		}
		j=k;
		for(k=0;k<=j;k++)
			cout<<s[i][k];
		cout<<endl;
	}			
	return 0;
}
