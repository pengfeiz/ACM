#include <iostream>
#include <string.h>
using namespace std;
char s[5][10];
double b[5]={9,4,4,4,7};
int main()
{
	int t=0,i,c[5];
	double a=0,d=0,z,p,y;
	while(scanf("%s",&s[0]))
	{
		memset(c,0,sizeof(c));
		if(strcmp(s[0],"-")==0)
		{
			if(t==0)
				break;
			else
			{
				printf("%.0lf%c\n",100*a/d,'%');
				t=a=d=0;
			}
			continue;
		}
		scanf("%s%s%s%s",s[1],s[2],s[3],s[4]);
		t=1;
		for(i=z=y=0;i<5;i++)
		{
			if(s[i][strlen(s[i])-1]=='g')
			{
				if(i==0)
					a+=atof(s[i])*b[i];
				y+=atof(s[i])*b[i];
				c[i]=1;
			}
			else if(s[i][strlen(s[i])-1]=='C')
			{
				if(i==0)
					a+=atof(s[i]);
				y+=atof(s[i]);
				c[i]=1;
			}
			else if(s[i][strlen(s[i])-1]=='%')
				z+=atof(s[i])/100;
		}
		p=y/(1-z);
		d+=p;
		if(!c[0])
			a+=p*atof(s[0])/100;
	}
	return 0;
}


				
			
