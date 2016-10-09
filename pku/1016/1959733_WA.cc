#include <iostream>
#include <string.h>
using namespace std;
void inventory(char a[100], char b[100])
{
	int i,j,tmp[100]={0};
	for(i=0;i<strlen(b);i++) 
		tmp[b[i]-'0']++;
	for(i=j=0;i<10;i++) 
	{
		if(tmp[i]>0) 
		{
			if(tmp[i]>=10) 
				a[j++]=tmp[i]/10+'0';
			a[j++]=tmp[i]%10+'0';
			a[j++]=i+'0';
		}
	}
	a[j]='\0';
	cout<<a<<endl;
}

int main()
{
	char s[16][100];
	int i,n;
	while(cin>>s[0]&&strcmp(s[0],"-1")!=0) 
	{
		for(n=0;n<15;n++) 
		{
			inventory(s[n+1],s[n]);
			if(strcmp(s[n+1],s[n])==0)
			{
				if(n==0)
					printf("%s is self-inventorying\n",s[0]);
				else
					printf("%s is self-inventorying after %d steps\n",s[0],n);
				break;
			}
			else 
			{
				for(i=n;i>=0;i--) 
					if(strcmp(s[n+1],s[i])==0) 
						break;
				if(i>=0) 
				{
					printf("%s enters an inventory loop of length %d\n",s[0],n+1-i);
					break;
				}
			}
		}
		if(n==15) 
			printf("%s can not be calssified after 15 iterations\n",s[0]);
	}
	return 0;
}
