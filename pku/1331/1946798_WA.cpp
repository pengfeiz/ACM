#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	char s1[10],s2[10],s3[10];
	long nn,l1,l2,l3,i,j,n,n1,n2,n3;
	cin>>nn;
	while(nn-->0)
	{
		cin>>s1>>s2>>s3;
		l1=strlen(s1);
		l2=strlen(s2);
		l3=strlen(s3);
		n=atof(s3);
		for(j=2;j<=n;j++)
		{
			n1=n2=n3=0;
			for(i=1;i<=l1;i++)
				n1+=(s1[i-1]-'0')*pow(j,l1-i);
			for(i=1;i<=l2;i++)
				n2+=(s2[i-1]-'0')*pow(j,l2-i);
			for(i=1;i<=l3;i++)
				n3+=(s3[i-1]-'0')*pow(j,l3-i);
			if(n1*n2==n3)
				break;
		}
		if(j==n+1)
			cout<<0<<endl;
		else
			cout<<j<<endl;
	}
	return 0;
}