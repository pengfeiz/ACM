#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#define MAX 256
char s[MAX];
int a[MAX][MAX],b[MAX][MAX];
int main()
{
//	ifstream cin("in.txt");
	int l,i,j,k;
	while(cin>>s)
	{
		l=strlen(s);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<l;i++)
			if(s[i]>='p'&&s[i]<='z')
				a[i][i]=1;
		for(i=1;i<l;i++)
			for(j=0;i+j<l;j++)
			{
				if(s[j]=='N'&&a[j+1][i+j])
					a[j][i+j]=1;
				if(s[j]=='C'||s[j]=='D'||s[j]=='E'||s[j]=='I')
				{
					for(k=j+1;k<i+j;k++)
					{
						if(a[j+1][k]&&a[k+1][i+j])
						{
							a[j][i+j]=1;
							break;
						}
					}
				}
			}
		if(a[0][l-1])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}


				

