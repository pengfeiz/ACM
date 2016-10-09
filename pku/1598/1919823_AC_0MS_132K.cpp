#include <iostream>
#include <string.h>
using namespace std;
char word[30][20];
int num[30];
int main()
{
	int n,m,i,j,k,ii,max,ll,l,t=0,begin;
	char s[30][80];
	while(cin>>n>>m)
	{
		if(t)
			cout<<endl;
		t++;
		max=0;
		for(i=0;i<m;i++)
			num[i]=0;
		cout<<"Excuse Set #"<<t<<endl;
		for(i=0;i<n;i++)
			cin>>word[i];
		scanf("\n");
		for(i=0;i<m;i++)
		{
			gets(s[i]);
			l=strlen(s[i]);
			begin=0;
			for(k=0;k<=l;k++)
			{
				if(!((s[i][k]<='z'&&s[i][k]>='a')||(s[i][k]>='A'&&s[i][k]<='Z')))
				{
					if((s[i][begin]<='z'&&s[i][begin]>='a')||(s[i][begin]<='Z'&&s[i][begin]>='A'))
					{
						for(j=0;j<n;j++)
						{
							ll=strlen(word[j]);
							for(ii=0;ii<ll;ii++)
								if(s[i][begin+ii]!=word[j][ii])
									if(s[i][begin+ii]-'A'+'a'!=word[j][ii])
										break;
							if(ii==ll&&!((s[i][begin+ii]<='z'&&s[i][begin+ii]>='a')||(s[i][begin+ii]<='Z'&&s[i][begin+ii]>='A')))
							{
								num[i]++;
								break;
							}
						}
					}
					begin=k+1;
				}
			}
			if(num[i]>max)
				max=num[i];
		}
		for(i=0;i<m;i++)
			if(num[i]==max)
			cout<<s[i]<<endl;
	}
	return 0;
}
						


