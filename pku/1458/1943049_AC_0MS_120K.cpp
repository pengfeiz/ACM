#include <iostream>
using namespace std;
#define MAX 1000
int main()
{
	char s[MAX],c[MAX];
	int num[MAX+1],i,j,l1,l2,t,p;
	while(cin>>s>>c)
	{
		l1=strlen(s);
		l2=strlen(c);
		t=0;
		for(j=0;j<=l2;j++)
			num[j]=0;
		for(i=0;i<l1;i++)
		{
			p=0;
			for(j=1;j<=l2;j++)
			{
				if(s[i]==c[j-1])
					t=num[j-1]+1;
				else
					t=num[j-1];
				if(t<p)
					t=p;
				if(t<num[j])
					t=num[j];
				num[j-1]=p;
				p=t;
			}
			num[l2]=p;
		}
		cout<<num[l2]<<endl;
	}
	return 0;
}


