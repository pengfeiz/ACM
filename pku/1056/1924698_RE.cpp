#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[500][500];
	int j,l,i,k,t,time=0;
	j=0;
	while(1)
	{
		cin>>s[j];
		if(strcmp(s[j],"9")==0)
		{
			time++;
			l=j;
			j=t=0;
			for(i=0;i<l-1&&t==0;i++)
				for(k=i+1;k<l&&t==0;k++)
					if(strstr(s[i],s[k])==s[i]||strstr(s[k],s[i])==s[k])
						t=1;
			if(t==0)
				cout<<"Set "<<time<<" is immediately decodable\n";
			else
				cout<<"Set "<<time<<" is not immediately decodable\n";
		}
		j++;
	}
	return 0;
}

