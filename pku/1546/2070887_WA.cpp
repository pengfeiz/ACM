#include <iostream>
using namespace std;
int main()
{
	int n,m,i,l,t,a[100];
	char s[100];
	while(scanf("%s%d%d",s,&n,&m)!=EOF)
	{
		l=strlen(s);
		t=0;
		for(i=0;i<l;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
				t=s[i]-'0'+t*n;
			else
				t=t*n+s[i]-'A'+10;
		}
		n=0;
		while(t>0)
		{
			a[n++]=t%m;
			t/=m;
		}
		memset(s,0,sizeof(s));
		for(i=n-1;i>=0;i--)
		{
			if(a[i]<10)
				s[n-i-1]=a[i]+'0';
			else
				s[n-i-1]=a[i]-10+'A';
		}
		s[n]='\0';
		printf("%7s\n",s);
	}
	return 0;
}

	

