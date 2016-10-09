#include <iostream>
using namespace std;
int main()
{
	char c[200][200];
	int i,j,l,n,t;
	while(cin>>n&&n!=0)
	{
		i=j=t=0;
		getchar();
		while((c[i][j]=getchar())!='\n')
		{
			if(t==0)
			{
				j++;
				if(j==n)
				{
					j=n-1;
					t=1;
					i++;
				}
			}
			else if(t==1)
			{
				j--;
				if(j==-1)
				{
					j=0;
					t=0;
					i++;
				}
			}
		}
		for(l=0;l<n;l++)
			for(j=0;j<i;j++)
				cout<<c[j][l];
		cout<<endl;
	}
	return 0;
}

