#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	char *s1,*s2;
	double total=0,n;
	char c;
	int nn;
	s1=(char *)malloc(100*sizeof(char));
	s2=(char *)malloc(100*sizeof(char));
	while(cin>>s1&&*s1!='#')
	{
		if(*s1=='0')
		{
			cout<<(int)total<<endl;
			total=0;
			cin>>s1;
		}
		cin>>s2>>n>>c;
		if(c=='F')
			total+=2*n;
		else if(c=='B')
		{
			nn=int(n*5);
			if(nn%10>=5)
				total+=n+nn/10+1;
			else
				total+=n+nn/10;
		}
		else
		{
			if(n<500)
				total+=500;
			else
				total+=n;
		}
	}
	return 0;
}