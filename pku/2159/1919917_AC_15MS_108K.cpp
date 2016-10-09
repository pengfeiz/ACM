#include <iostream>
#include <string.h>
using namespace std;
char s1[200],s2[200];
int main()
{
	int n,l2,num[26],i,tt[150],tt2[150];
	cin>>s1>>s2;
	n=strlen(s1);
	l2=strlen(s2);
	if(n!=l2)
		cout<<"NO\n";
	else
	{
		for(i=0;i<26;i++)
			num[i]=0;
		for(i=0;i<150;i++)
			tt[i]=tt2[i]=0;
		for(i=0;i<n;i++)
			if(s1[i]<='Z'&&s1[i]>='A')
				num[s1[i]-'A']++;
		for(i=0;i<26;i++)
			tt[num[i]]++;
		for(i=0;i<26;i++)
			num[i]=0;
		for(i=0;i<n;i++)
			if(s2[i]<='Z'&&s2[i]>='A')
				num[s2[i]-'A']++;
		for(i=0;i<26;i++)
			tt2[num[i]]++;
		for(i=0;i<150;i++)
			if(tt[i]!=tt2[i])
				break;
		if(i!=150)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}

		

