#include <iostream.h>
#include <string.h>
#include <iomanip.h>
#include <stdlib.h>

char c[100000][7];
int n[100000];

int compare(const void * a,const void * b)
{
	return *((int*)a)-*((int*)b);
}

int dosth(char c[7])
{
	int i,nn=0;
	for(i=0;i<7;i++)
	{
		if(c[i]>='A'&&c[i]<='C')
			nn=10*nn+2;
		else if(c[i]<='F'&&c[i]>='D')
			nn=10*nn+3;
		else if(c[i]>='G'&&c[i]<='I')
			nn=10*nn+4;
		else if(c[i]>='J'&&c[i]<='L')
			nn=10*nn+5;
		else if(c[i]>='M'&&c[i]<='O')
			nn=10*nn+6;
		else if(c[i]>='P'&&c[i]<='S'&&c[i]!='Q')
			nn=10*nn+7;
		else if(c[i]>='T'&&c[i]<='V')
			nn=10*nn+8;
		else if(c[i]>='W'&&c[i]<='Y')
			nn=10*nn+9;
		else
			nn=10*nn+c[i]-'0';
	}
	return nn;
}

int main()
{
	int nn,i,l,t;
	char cc;
	cin>>nn;
	for(i=0;i<nn;i++)
	{
		l=0;
		while(l<7)
		{
			cin>>cc;
			if(cc=='-')
				continue;
			c[i][l]=cc;
			l++;
		}
		n[i]=dosth(c[i]);
	}
    qsort(n,nn,sizeof(int),compare);
	t=0;
	for(i=0;i<nn;i++)
	{
		l=1;
		while(n[i]==n[i+1]&&i<nn-1)
		{	
			l++;
			i++;
		}
		if(l>1)
		{
			t=1;
			cout<<setfill('0')<<setw(3)<<n[i]/10000<<"-"<<setfill('0')<<setw(4)<<n[i]%10000<<" "<<l<<endl;
		}
	}
	if(t==0)
		cout<<"No duplicates.\n";
	return 0;
}
