#include  <iostream>
using namespace std;
int main()
{
	int n,num[1001],i,j,q,w,nn;
	char p;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n;
		for(i=0;i<1001;i++)
			num[i]=0;
		for(i=1;i<=n;i++)
		{
			cin>>p>>q>>w;
			for(j=q;j<=w;j++)
				num[j]++;
		}
		for(i=0;i<=1000;i++)
			if(num[i]!=0)
				cout<<char(num[i]+'A'-1);
		cout<<endl;
	}
	return 0;
}


