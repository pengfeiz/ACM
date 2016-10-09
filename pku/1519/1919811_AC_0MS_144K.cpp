#include <iostream>
#define MAX 10000
using namespace std;
int dosth(int n[MAX],int &i)
{
	int m=0,j;
	if(i==1)
		return n[0];
	else
	{
		for(j=0;j<i;j++)
			m+=n[j];
		i=0;
		while(m!=0)
		{
			n[i]=m%10;
			m=m/10;
			i++;
		}
		return dosth(n,i);
	}
}

int main()
{
	int n[MAX],i;
	char c;
	while((c=getchar())!='0')
	{
		i=0;
		if(c>=48&&c<58)
		{
			n[i]=c-48;
			i++;
		}
		while((c=getchar())!='\n')
		{
			n[i]=c-48;
			i++;
		}
		cout<<dosth(n,i)<<endl;
	}
	return 0;
}

