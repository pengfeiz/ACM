#include <iostream>
using namespace std;
char s[100][200],c[200];
int main()
{
	int m=1,i=1;
	strcpy(s[0],"http://www.acm.org/");
	while(gets(c))
	{
		if(strcmp(c,"QUIT")==0)
			break;
		else if(strstr(c,"VISIT")==c)
		{
			i=m;
			strcpy(s[i],c);
			m++;
		}
		else if(strcmp(c,"BACK")==0)
		{
			i--;
			if(i>=0)
				cout<<s[i]+6<<endl;
			else
				cout<<"Ignored\n";
		}
		else if(strcmp(c,"FORWARD")==0)
		{
			i++;
			if(i<m)
				cout<<s[i]+6<<endl;
			else
				cout<<"Ignored\n";
		}
	}
	return 0;
}

