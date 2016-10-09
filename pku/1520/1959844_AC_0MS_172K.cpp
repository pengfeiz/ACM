#include <iostream>
#include <string.h>
using namespace std;
void change(char s[30])
{
	int i,l=strlen(s);
	for(i=0;i<l;i++)
		if(s[i]<='Z'&&s[i]>='A')
			s[i]-='A'-'a';
}
int main()
{
	char s[2][1000][50],c[50];
	int num[1000],n,i,j,k;
	while(cin>>s[0][0]&&strcmp(s[0][0],".")!=0)
	{
		n=0;
		while(s[0][n][strlen(s[0][n])-1]!='.')
		{
			s[0][n][strlen(s[0][n])-1]='\0';
			strcpy(s[1][n],s[0][n]);
			n++;
			cin>>s[0][n];
		}
		s[0][n][strlen(s[0][n])-1]='\0';
		strcpy(s[1][n],s[0][n]);
		n++;
		for(i=0;i<n;i++)
		{
			if((s[1][i][0]<='9'&&s[1][i][0]>='0')||s[1][i][0]=='-')
				num[i]=0;
			else
				num[i]=1;
		}
		for(i=0;i<n;i++)
			change(s[1][i]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				if(num[i]!=num[j])
					continue;
				if(num[i]==0&&atof(s[1][i])>atof(s[1][j]))
				{
					for(k=0;k<2;k++)
					{
						strcpy(c,s[k][i]);
						strcpy(s[k][i],s[k][j]);
						strcpy(s[k][j],c);
					}					
				}
				else if(num[i]==1&&strcmp(s[1][i],s[1][j])>0)
				{
					for(k=0;k<2;k++)
					{
						strcpy(c,s[k][i]);
						strcpy(s[k][i],s[k][j]);
						strcpy(s[k][j],c);
					}	
				}
			}
		for(i=0;i<n;i++)
		{
			if(i)
				cout<<", ";
			cout<<s[0][i];
		}
		cout<<".\n";
	}
	return 0;
}
