#include <iostream>
using namespace std;
__int64 judge(__int64 a)
{
	__int64 i=0,b=a;
	while(b>0)
	{
		i++;
		b/=10;
	}
	return i;
}
int main()
{
	__int64 n1,n2,num[100],i,j,no[100],l,x;
	int time=0;
	while(scanf("%I64d%I64d",&n1,&n2)&&(n1&&n2))
	{
		i=0;
		time++;
		cout<<"Case "<<time<<":\n";
		printf("%I64d / %I64d\n",n1,n2);
		while(n1%n2!=0)
		{
			x=n1/n2;
			num[i]=x;
			x=n1%n2;
			n1=n2;
			n2=x;
			i++;
		}
		num[i]=n1/n2-1;
		l=i;
		no[l+1]=1;
		for(j=l;j>=0;j--)
			no[j]=no[j+1]+3+judge(num[j]);
		for(i=0;i<=l;i++)
		{
			for(j=1;j<=no[0];j++)
			{
				if(j==no[0]-no[i+1]/2)
					cout<<1;
				else
					cout<<".";
			}
			cout<<endl;
			for(j=0;j<no[0]-no[i];j++)
				cout<<".";
			printf("%I64d.+.",num[i]);
			for(j=0;j<no[i+1];j++)
				cout<<"-";
			cout<<endl;
		}
		for(i=1;i<no[0];i++)
			cout<<".";
		cout<<"1\n";
	}
	return 0;
}


	
