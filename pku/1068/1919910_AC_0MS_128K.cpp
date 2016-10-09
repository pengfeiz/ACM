#include <iostream>
#include <string.h>
#define MAX 20
using namespace std;			

void turn(int length)
{
	int i,j,t,t2,t3,l[MAX];
	char ca[2*MAX];
	for(i=0;i<length;i++)
	{
		cin>>l[i];
	}
	l[i]='\0';
	i=j=0;
	t=l[0];
	t2=t3=0;
	while(t2<2*length)
	{
		for(j=0;j<t;j++)
		{
			ca[j+t2]='(';
		}
		ca[j+t2]=')';
		t2=j+t2+1;
		if(t2<2*length)
		t=l[i+1]-l[i];
		i++;
	}
	for(i=0;i<2*length;i++)
	{
		t=t2=0;
		if(ca[i]==')')
		{
			for(j=i;j>=0;j--)
			{
				if(ca[j]==')')
				{
					t2++;
					t++;
				}
				else t2--;
				if(t2==0&&i!=2*length-1)
				{
					cout<<t<<' ';
					break;
				}
				else if(t2==0)
				{
					cout<<t<<'\n';
					break;
				}
			}
		}
	}
}

int main()
{
	int i,n,m;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m;
		turn(m);
	}
	return 0;
}
	



