#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char c[9][24];
int main()
{
	int n,i,j,k,num;
	cin>>n;
	for(k=0;k<n;k++)
	{
		cin>>c[k];
		for(i=0;i<4;i++)
		{
			num=0;
			for(j=0;j<8;j++)
				num+=(int)pow(2,(double)(7-j))*(int)(c[k][i*8+j]-'0');
			cout<<num;
			if(i<3)
				cout<<".";
			else
				cout<<endl;
		}
	}
	return 0;
}


