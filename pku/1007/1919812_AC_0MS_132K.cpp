#include <iostream>
using namespace std;
char c[100][100];
int n[100][2];
int main()
{
	int nn,i,j,k,l;
	cin>>nn>>l;
	for(i=0;i<l;i++)
	{
		n[i][0]=0;
		n[i][1]=i;
		for(j=0;j<nn;j++)
			cin>>c[i][j];
		for(j=0;j<nn-1;j++)
			for(k=j+1;k<nn;k++)
				if(c[i][j]>c[i][k])
					n[i][0]++;
	}
	for(i=0;i<l-1;i++)
		for(j=i+1;j<l;j++)
			if(n[i][0]>n[j][0]||(n[i][0]==n[j][0]&&n[i][1]<n[j][1]))
			{
				k=n[i][0];
				n[i][0]=n[j][0];
				n[j][0]=k;
				k=n[i][1];
				n[i][1]=n[j][1];
				n[j][1]=k;
			}
	for(i=0;i<l;i++)
		cout<<c[n[i][1]]<<endl;
	return 0;
}

				

