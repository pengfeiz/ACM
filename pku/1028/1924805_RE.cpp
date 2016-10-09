#include <iostream>
using namespace std;
char s[100][200],c[200];
int main()
{
	int m=1,i=0;
	strcpy(s[0],"VISIT http://www.acm.org/");
	while(gets(c))
	{
		if(strcmp(c,"QUIT")==0)
			break;
		else if(strstr(c,"VISIT")==c)
		{
			i++;
			m=i+1;
			strcpy(s[i],c);
			cout<<s[i]+6<<endl;
		}
		else if(strcmp(c,"BACK")==0)
		{
			i--;
			if(i>=0)
				cout<<s[i]+6<<endl;
			else
			{
				i=0;
				cout<<"Ignored\n";
			}
		}
		else if(strcmp(c,"FORWARD")==0)
		{
			i++;
			if(i<m)
				cout<<s[i]+6<<endl;
			else
			{
				i=m-1;
				cout<<"Ignored\n";
			}
		}
	}
	return 0;
}

