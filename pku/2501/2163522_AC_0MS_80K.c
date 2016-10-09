#include <string.h>
#include <stdlib.h>
main()
{
	double a,t,l,v;
	char s[20];
	t=l=v=0;
	while(gets(s))
	{
		a=(s[0]-'0')*10+s[1]-'0';
		a=a*60+(s[3]-'0')*10+s[4]-'0';
		a=a*60+(s[6]-'0')*10+s[7]-'0';
		l+=(a-t)*v/3600;
		t=a;
		if(strlen(s)<=8)
			printf("%s %.2lf km\n",s,l);
		else
			v=atof(s+8);
	}
}


