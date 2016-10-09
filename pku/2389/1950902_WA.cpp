#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s1[42],s2[42];
	cin>>s1>>s2;
	int l1,l2,i,j;
	int a[42],b[42],c[100]={0};
	l1=strlen(s1);
	l2=strlen(s2);
	for(i=0;i<l1;i++)
		a[i]=s1[i]-'0';
	for(i=0;i<l2;i++)
		b[i]=s2[i]-'0';
	for(i=l1-1;i>=0;i--)
	{
		for(j=0;j<l2;j++)
			c[j+i]+=b[j]*a[i];
		for(j=99;j>0;j--)
			if(c[j]>9)
			{
				c[j-1]+=c[j]/10;
				c[j]%=10;
			}
	}
	for(i=99;i>0;i--)
		if(c[i]!=0)
			break;
	for(j=0;j<=i;j++)
		cout<<c[j];
	cout<<endl;
	return 0;
}