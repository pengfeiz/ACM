#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int t1,t2,i,l,t;
	char *s,c;
	s=(char*)malloc(1000*sizeof(char));
	while(cin>>s&&strcmp(s,"end")!=0)
	{
		c='1';
		t1=t2=0;
		t=1;
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(*(s+i)=='a'||*(s+i)=='e'||*(s+i)=='i'||*(s+i)=='o'||*(s+i)=='u')
			{
				t=0;
				t1++;
				t2=0;
				if(t1==3)
				{
					t=1;
					break;
				}
				else if(*(s+i)==c&&c!='e'&&c!='o')
				{
					t=1;
					break;
				}
				else c=*(s+i);
			}
			else 
			{
				t2++;
				t1=0;
				if(t2==3)
				{
					t=1;
					break;
				}
				else if(*(s+i)==c)
				{
					t=1;
					break;
				}
				else
					c=*(s+i);
			}
		}
		if(t==0)
			cout<<"<"<<s<<"> is acceptable.\n";
		else
			cout<<"<"<<s<<"> is not acceptable.\n";
	}
	return 0;
}


