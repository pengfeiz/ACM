#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
#define MAX 10000
#define MAX2 50
char s[MAX][20];
char c[MAX2][20];
int a[MAX],b[MAX];
int main()
{
	int n=0,i,m=0,j,t,l,k;
	while(1)
	{
		cin>>s[n];
		if(!strcmp(s[n],"#"))
			break;
		b[n]=strlen(s[n]);
		n++;
	}
	while(1)
	{
		cin>>c[m];
		if(!strcmp(c[m],"#"))
			break;
		m++;
	}
	for(i=0;i<m;i++)
	{
		memset(a,0,sizeof(a));
		a[0]=1;
		l=strlen(c[i]);
		for(j=0;j<n;j++)
		{
			t=0;
			if(abs(l-b[j])>1)
				continue;
			if(strcmp(c[i],s[j])==0)
			{
				a[0]=0;
				break;
			}
			else if(l<b[j])
			{
				for(k=t=0;k<b[j];k++)
				{
					if(c[i][k]!=s[j][k+t])
					{
						t++;
						k--;
					}
					if(t>1)
						break;
				}
			}
			else if(l==b[j])
			{
				for(k=t=0;k<l;k++)
				{
					if(c[i][k+t]!=s[j][k])
						t++;
					if(t>1)
						break;
				}
			}
			else if(l>b[j])
			{
				for(k=t=0;k<l;k++)
				{
					if(c[i][k+t]!=s[j][k])
					{
						t++;
						k--;
					}
					if(t>1)
						break;
				}
			}
			if(t==1)
			{
				a[a[0]]=j;
				a[0]++;
			}					
		}
		if(a[0]==0)
			printf("%s is correct\n",c[i]);
		else
		{
			printf("%s:",c[i]);
			for(j=1;j<a[0];j++)
				printf(" %s",s[a[j]]);
			printf("\n");
		}
	}
	return 0;
}
	

	
