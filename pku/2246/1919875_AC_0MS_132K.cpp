#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define MAX 1000

struct gao
{
	char c;
	int n1,n2;
};

gao he[MAX];
int nn,num;

int find(char c)
{
	int i;
	for(i=0;i<nn;i++)
		if(he[i].c==c)
			return i;
	return -1;
}

void compute(char *s,int l,int &m)
{
	int i,j,t,t1,t2;
	t=0;
	if(l==1||m==-1)
		return;
	t=0;
	for(i=1;i<l;i++)
	{
		if(*(s+i)=='(')
			t++;
		else if(*(s+i)==')')
			t--;
		else
			t1=i;
		if(t==0)
			break;
	}
	t=0;
	for(j=l-2;j>=0;j--)
	{
		if(*(s+j)=='(')
			t--;
		else if(*(s+j)==')')
			t++;
		else
			t2=j;
		if(t==0)
			break;
	}
	if(he[find(*(s+t1))].n2!=he[find(*(s+t2))].n1)
	{
		m=-1;
		return;
	}
	for(t=1;t<l;t++)
		if(*(s+t)!='('&&*(s+t)!=')')
			break;
	for(i=l-2;i>=0;i--)
		if(*(s+i)!='('&&*(s+i)!=')')
			break;
	num+=he[find(*(s+t))].n1*he[find(*(s+t1))].n2*he[find(*(s+i))].n2;
	compute(s+1,j-1,m);
	compute(s+j,l-1-j,m);
}

int main()
{
	char *s,l;
	int i,m;
	s=(char *)malloc(1000*sizeof(char));
	cin>>nn;
	for(i=0;i<nn;i++)
		cin>>he[i].c>>he[i].n1>>he[i].n2;
	while(cin>>s)
	{
		num=m=0;
		l=strlen(s);
		compute(s,l,m);
		if(m==-1)
			cout<<"error\n";
		else
			cout<<num<<endl;
	}
	return 0;
}
		
