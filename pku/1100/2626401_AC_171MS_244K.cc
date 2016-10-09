#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define MAX 1024
#define esp 1e-10

char *s,c[MAX];
int a[MAX],m;
bool f,ff,fff;

int read();
int muldiv();
int addsub();
bool dosth();

int read()
{
	int y=0,i=1;
	while(*s<='9'&&*s>='0')
	{
		y=y+(*s-'0')*i;
		i*=10;
		s--;
	}
	if(*s==')')
	{
		s--;
		y=addsub();
		s--;
	}
	return y;
}

int addsub()
{
	int y=0;
	y=read();
	if(*s=='-'||*s=='+')
	{
		s--;		
		if(*(s+1)=='-')
			y=addsub()-y;
		else 
			y+=addsub();
	}
	else if(*s=='*')
	{
		s--;
		y*=addsub();
	}
	return y;
}

bool dosth()
{
	int l,r;
	s=c+strlen(c)-1;
	l=addsub();
	s--;
	r=addsub();
	return l==r;
}

int bulid(int u)
{
	if(u==m)
	{
		if(dosth())
			return true;
		return false;
	}
	c[a[u]]='+';
	if(bulid(u+1))
		return true;
	c[a[u]]='-';
	if(bulid(u+1))
		return true;
	c[a[u]]='*';
	if(bulid(u+1))
		return true;
	return false;
}

int main()
{
	int i,l,kk=0,q,j;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(gets(c),strcmp(c,"0"))
	{
		ff=true;
		f=fff=false;
		kk++;
		l=strlen(c);
		j=0;
		for(q=0;q<l;q++)
		{
			if(c[q]=='=')
			{
				f=fff=false;
				ff=true;
			}
			else if(c[q]==' ')
			{
				for(i=q;i<l;i++)
					c[i]=c[i+1];
				l--;
				q--;
				if(!ff)
					f=false;
				fff=false;
			}
			else if(!f&&((c[q]>='0'&&c[q]<='9')||c[q]=='('))
			{
				if(ff)
				{
					if(c[q]>='0'&&c[q]<='9')
					{
						ff=false;
						f=true;
					}
					fff=true;
					continue;
				}
				if(c[q]>='0'&&c[q]<='9')
					fff=true;
				l++;
				for(i=l+1;i>q;i--)
					c[i]=c[i-1];

				c[q++]=' ';
				f=true;
			}
			else if(fff&&c[q]=='(')
			{
				for(i=l;i>q;i--)
					c[i]=c[i-1];
				l++;
				c[q++]=' ';
				f=true;
				fff=false;
			}
			else if(c[q]==')')
				f=fff=false;
		}
		q=0;
		for(i=0;i<l;i++)
			if(c[i]=='=')
				break;
		if(c[i+1]==' ')
			q++;
		if(c[i-1]==' ')
		{
			q++;
			c[i-1]='=';
		}
		else
			i++;
		for(;i<=l-q;i++)
			c[i]=c[i+q];
		l=strlen(c);
		while(c[l-1]==' ')
			c[l-1]=c[l--];
		m=0;
		for(i=0;i<l;i++)
			if(c[i]==' ')
				a[m++]=i;
		printf("Equation #%d:\n",kk);
		if(bulid(0))
			printf("%s\n",c);
		else
			printf("Impossible\n");
		printf("\n");
	}
	return 0;
}

