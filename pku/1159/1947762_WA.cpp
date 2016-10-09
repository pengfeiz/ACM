#include <iostream>
#include <string.h>
using namespace std;
char s[5000];
int main()
{
	int l,i,t,j,p;
	while(cin>>l)
	{
		t=p=0;
		cin>>s;
		for(i=0,j=l-1;i!=j;)
		{
			if(s[i]!=s[j])
			{
				if(p==0)
				{
					i++;
					p=1;
				}
				else if(p==1)
				{
					j--;
					p=0;
				}
				t++;
			}
			else
			{
				i++;
				j--;
			}
		}
		cout<<t<<endl;
	}
	return 0;
}


