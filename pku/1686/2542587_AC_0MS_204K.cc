#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 300
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
	if(*s<='9'&&*s>='0')
	{
		y=*s-'0';
		s++;
	}
	if(*s>='a'&&*s<='z')
	{
		y=ss[*s-'a'];
		s++;
		while(*s==' ')
			s++;
		return y;
	}
	if(*s=='(')
	{
		s++;
		y=addsub();
		s++;
	}
	while(*s==' ')
		s++;
	return y;
}


int muldiv()
{
	while(*s==' ')
		s++;
	int y;
	y=read();
	while(*s==' ')
		s++;
	if(*s=='*')
	{
		s++;
		y*=muldiv();
		while(*s==' ')
			s++;
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
	while(*s==' ')
		s++;
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
		while(*s==' ')
			s++;
	}
	return y;
}

bool dosth()
{
	int l,r;
	gets(c);
	s=c;
	l=addsub();	
	gets(c);
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
	getchar();
	while(tt--)
	{
		if(dosth())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

