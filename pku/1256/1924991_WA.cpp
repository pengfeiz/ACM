#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n,l;
void sortt(char s[13])
{
	int i,j;
	char c;
	for(i=0;i<l-1;i++)
		for(j=i+1;j<l;j++)
			if(s[i]>s[j])
			{
				c=s[i];
				s[i]=s[j];
				s[j]=c;
			}
}
void cc(char s[13])
{
	int i;
	for(i=0;i<l;i++)
		cout<<char(s[i]);
	cout<<endl;
}
int main()
{
	char s[13];
	cin>>n;
	while(n-->0)
	{
		cin>>s;
		l=strlen(s);
		sortt(s);
		do{
			cc(s);
		}while(next_permutation(s,s+l));
	}
	return 0;
}


