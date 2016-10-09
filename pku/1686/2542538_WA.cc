#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 128
#define esp 1e-10

char *s,c[MAX],ss[26];

int read();
int muldiv();
int addsub();
bool dosth();

int read()
{
	while(*s==' ')
		s++;
	int y=0;
	while(*s<='9'&&*s>='0')
	{
		y=y*10+*s-'0';
		s++;
	}
	if(*s>='a'&&*s<='z')
	{
		y=ss[*s-'a'];
		s++;
		return y;
	}
	if(*s=='(')
	{
		s++;
		y=addsub();
		s++;
	}
	return y;
}


int muldiv()
{
	while(*s==' ')
		s++;
	int y;
	y=read();
	if(*s=='*')
	{
		s++;
		y*=muldiv();
	}
	return y;
}

int addsub()
{
	while(*s==' ')
		s++;
	int y=0;
	int b=0;
	if(*(s-1)=='-')
		b=1;
	y=muldiv();
	if(*s=='-'||*s=='+')
	{
		s++;
		if(!b)
		{			
			if(*(s-1)=='-')
				y-=addsub();
			else 
				y+=addsub();
		}
		if(b)
		{			
			if(*(s-1)=='-')
				y+=addsub();
			else 
				y-=addsub();
		}
	}
	return y;
}

bool dosth()
{
	int l,r;
	scanf("%s",c);
	s=c;
	l=addsub();
	scanf("%s",c);
	s=c;
	r=addsub();
	return (l-r)==0;
}

int main()
{
	int i,tt;
	for(i=0;i<26;i++)
		ss[i]=i+1;
//	freopen("in.txt","r",stdin);
	scanf("%d",&tt);
	while(tt--)
	{
		if(dosth())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

