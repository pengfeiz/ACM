#include <iostream>
#include <string.h>
using namespace std;
char s[50],ss[50];
int a[100];
void dosth1()
{
	char ha[50];
	int l,p=0,q,i,t=0;
	l=strlen(s);
	for(i=0;i<l;i++)
		a[l-i]=s[i]-'0';
	a[0]=l;
	memset(ss,0,sizeof(ss));
	while(a[0])
	{
		a[1]--;
		for(i=1;i<=l;i++)
		{
			if(a[i]<0)
			{
				a[i]+=10;
				a[i+1]--;
			}
			else
				break;
		}
		q=0;
		for(i=a[0];i>0;i--)
		{
			q=10*q+a[i];
			a[i]=q/26;
			q%=26;
		}
		while(a[a[0]]==0&&a[0])
			a[0]--;
		ss[p++]=q%26+'a';
	}
	ss[p]='\0';
	for(i=0;i<p;i++)
		ha[i]=ss[p-i-1];
	ha[p]='\0';
	printf("%-22s",ha);
	p=(3-l%3)%3;
	for(i=0;i<l;i++)
	{
		printf("%c",s[i]);
		p++;
		if(p%3==0&&i!=l-1)
		{
			p=0;
			printf(",");
		}
	}
	printf("\n");
}
	
void dosth2()
{
	int i,l,j;
	l=strlen(s);
	a[0]=1;
	for(i=0;i<l;i++)
	{
		for(j=1;j<=a[0];j++)
			a[j]*=26;
		a[1]+=s[i]-'a'+1;
		for(j=1;j<a[0];j++)
		{
			a[j+1]+=a[j]/1000;
			a[j]%=1000;
		}
		while(a[a[0]]>999)
		{
			a[a[0]+1]=a[a[0]]/1000;
			a[a[0]]%=1000;
			a[0]++;
		}
	}
	printf("%-22s%d",s,a[a[0]]);
	for(i=a[0]-1;i>0;i--)
		printf(",%03d",a[i]);
	printf("\n");
}

int main()
{
	while(cin>>s&&strcmp(s,"*"))
	{
		memset(a,0,sizeof(a));
		if(s[0]<='9'&&s[0]>=0)
			dosth1();
		else
			dosth2();
	}
	return 0;
}
