#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
void change(char *s)
{
	int i,l;
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(*(s+i)<=90&&*(s+i)>=65)
			cout<<(char)((*(s+i)-65+21)%26+65);
		else
			cout<<*(s+i);
	}
}

int main()
{
	char *s;
	int t;
	s=(char *)malloc(200*sizeof(char));
	while(1)
	{
		gets(s);
		if(strcmp(s,"ENDOFINPUT")==0)
			break;
		else if(strcmp(s,"START")==0)
			t=1;
		else if(strcmp(s,"END")==0)
			continue;
		else
		{
			change(s);
			cout<<endl;
		}
	}
	return 0;
}
