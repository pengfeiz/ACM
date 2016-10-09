#include <iostream>
using namespace std;
int main()
{
	int nn,i,j,k,t,tt,n;
	cin>>nn;
	for(i=0;i<nn;i++)
	{
		tt=1;
		cin>>n;
		for(j=2;j<=n;j++)
		{
			k=0;
			for(t=2;t<=j;t++)
				if(j%t==0)
					k++;
			if(k%2==0)
				tt++;
		}
		cout<<tt<<endl;
	}
	return 0;
}