#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s1[8],s2[8],c[8];
	int num[12],n,i,j,ll[12];
	cin>>n;
	while(n-->0)
	{
		for(i=0;i<12;i++)
			num[i]=-1;
		for(j=0;j<3;j++)
		{
			cin>>s1>>s2>>c;
			for(i=0;i<12;i++)
				ll[i]=0;
			if(strcmp(c,"even")==0)
				for(i=0;i<strlen(s1);i++)
					num[s1[i]-'A']=num[s2[i]-'A']=1;
			else if(strcmp(c,"up")==0)
			{
				for(i=0;i<strlen(s1);i++)
				{
					if(num[s1[i]-'A']==-1)
						num[s1[i]-'A']=2;
					else if(num[s1[i]-'A']==0)
						num[s1[i]-'A']=1;
					if(num[s2[i]-'A']==-1)
						num[s2[i]-'A']=0;
					else if(num[s2[i]-'A']==2)
						num[s2[i]-'A']=1;
					ll[s1[i]-'A']=ll[s2[i]-'A']=1;
				}
				for(i=0;i<12;i++)
					if(ll[i]==0)
						num[i]=1;
				for(i=0;i<12;i++)
					ll[i]=0;
			}
			else 
			{
				for(i=0;i<strlen(s1);i++)
				{
					if(num[s1[i]-'A']==-1)
						num[s1[i]-'A']=0;
					else if(num[s1[i]-'A']==2)
						num[s1[i]-'A']=1;
					if(num[s2[i]-'A']==-1)
						num[s2[i]-'A']=2;
					else if(num[s2[i]-'A']==0)
						num[s2[i]-'A']=1;
					ll[s1[i]-'A']=ll[s2[i]-'A']=1;
				}
				for(i=0;i<12;i++)
					if(ll[i]==0)
						num[i]=1;
				for(i=0;i<12;i++)
					ll[i]=0;
			}				
		}
		for(i=0;i<12;i++)
			if(num[i]!=1)
				break;
		if(num[i]==0)
			cout<<char(i+'A')<<" is the counterfeit coin and it is light.\n";
		else
			cout<<char(i+'A')<<" is the counterfeit coin and it is heavy.\n";
	}
	return 0;
}



