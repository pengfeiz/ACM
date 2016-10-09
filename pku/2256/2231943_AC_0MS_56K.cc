#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

int kase=0;
char line[100],*cp;
double p,u,i;

void read (double* res)
{
	cp++;
	if (*cp!='=') 
		return;
	cp++;
	sscanf(cp,"%lf",res);
	while(!isalpha(*cp)) 
		cp++;
	if(*cp=='m') 
		*res/=1000.0;
	if(*cp=='k')
		*res*=1000.0;
	if(*cp=='M')
		*res*=1000000.0;
}

void solve_case()
{
	gets(line);
	p=u=i=-1;
	for(cp=line;*cp;cp++)
		switch(*cp)
		{	
			case 'P': read(&p); break;
			case 'U': read(&u); break;
			case 'I': read(&i); break;
		}
  printf("Problem #%d\n",++kase);
  if(p>=0&&u>=0) 
	  printf("I=%.2fA\n\n",p/u);
  if(p>=0&&i>=0) 
	  printf("U=%.2fV\n\n",p/i);
  if(u>=0&&i>=0) 
	  printf("P=%.2fW\n\n",u*i);
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
		solve_case();
	return 0;
}
