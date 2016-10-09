#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1003
char s[MAX];
int l;
bool p,q,r,c,t,f;

bool dosth()
{
	bool x,y;
	if(s[l]=='p')
	{
		l++;
		return p;
	}
	if(s[l]=='q')
	{
		l++;
		return q;
	}
	if(s[l]=='r')
	{
		l++;
		return r;
	}
	if(s[l]=='s')
	{
		l++;
		return c;
	}
	if(s[l]=='t')
	{
		l++;
		return t;
	}
	if(s[l]=='N')
	{
		l++;
		x=dosth();
		return !x;
	}
	if(s[l]=='K')
	{
		l++;
		x=dosth();
		y=dosth();
		return x&&y;
	}
	if(s[l]=='A')
	{
		l++;
		x=dosth();
		y=dosth();
		return x||y;
	}
	if(s[l]=='E')
	{
		l++;
		x=dosth();
		y=dosth();
		return x==y;
	}
	if(s[l]=='C')
	{
		l++;
		x=dosth();
		y=dosth();
		if(x&&!y)
			return false;
		return true;
	}
	l++;
	return dosth();
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(gets(s),strcmp(s,"0"))
	{
		f=true;
		for(i=0;f&&i<32;i++)
		{
			p=((i&1)==1);
			q=((i&2)==2);
			r=((i&4)==4);
			c=((i&8)==8);
			t=((i&16)==16);
			l=0;
			f=dosth();
		}
		if(f)
			printf("tautology\n");
		else
			printf("not\n");
	}
	return 0;
}
			