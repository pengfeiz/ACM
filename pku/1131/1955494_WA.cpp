#include <iostream>
#include <string.h>
using namespace std;
int l,qq[1000],t;;
char c[30];
void dosth(int p)
{
	int j,q[1000],x=p,y,z;
	memset(q,0,1000);
	q[p-1]=c[p+1]-'0';
	while(p-->0)
	{
		j=x;
		do		
		{
			y=q[j-1];
			z=q[j];
			q[j]=(10*y+z)%8;
			q[j-1]=(10*y+z)/8;
			j++;
		}while((10*y+z)%8!=0||j<x);
		if(l<j-1)
			l=j-1;
	}
	for(j=0;j<l;j++)
		qq[j]+=q[j];
}		
int main()
{
	int lc,i;
	while(cin>>c)
	{
		l=1;
		if(strcmp(c,"0")==0)
		{
			cout<<"0 [8] = 0 [10]\n";
			continue;
		}
		else if(strcmp(c,"1")==0)
		{
			cout<<"1 [8] = 1 [10]\n";
			continue;
		}
		lc=strlen(c)-2;
		memset(qq,0,1000);
		for(i=1;i<=lc;i++)
			dosth(i);				
		cout<<c<<" [8] = 0.";
		for(i=l-1;i>0;i--)
			if(qq[i]>9)
			{
				qq[i-1]+=qq[i]/10;
				qq[i]%=10;
			}
		for(l=l-1;l>0;l--)
			if(qq[l]!=0)
				break;
		for(i=0;i<=l;i++)
			cout<<qq[i];
		cout<<" [10]\n";
	}
	return 0;
}