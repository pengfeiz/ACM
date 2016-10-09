#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[100][100],c1[100],c2[100];
	int n,i,nn,min,l,k,j,t,max;
	cin>>nn;
	while(nn-->0)
	{
		l=200;
		max=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			if(strlen(s[i])<l)
			{
				min=i;
				l=strlen(s[i]);
			}
		}
		for(i=0;i<l;i++)
			for(j=i;j<l;j++)
			{
				for(k=0;k<=j-i;k++)
					c1[k]=s[min][i+k];
				for(k=0;k<=j-i;k++)
					c2[k]=s[min][j-k];
				c1[k]=c2[k]='\0';
				t=1;
				for(k=0;k<n&&t==1;k++)
				{
					if(strstr(s[k],c1)==NULL&&strstr(s[k],c2)==NULL)
						t=0;
				}
				if(t==1&&j-i+1>max)
					max=j-i+1;
			}
		cout<<max<<endl;
	}
	return 0;
}



