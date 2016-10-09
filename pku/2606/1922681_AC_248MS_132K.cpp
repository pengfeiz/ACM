#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
	double num[200][2];
	int n,i,j,k,max,t;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>num[i][0]>>num[i][1];
	max=0;
	for(i=0;i<n-2;i++)
	{
		for(j=i+1;j<n-1;j++)
		{
			t=2;
			for(k=j+1;k<n;k++)
			{
				if(fabs((num[j][0]-num[i][0])*(num[k][1]-num[i][1])-(num[j][1]-num[i][1])*(num[k][0]-num[i][0]))<0.01)
					t++;
			}
			if(t>max)
				max=t;
		}
	}
	cout<<max<<endl;
	return 0;
}

