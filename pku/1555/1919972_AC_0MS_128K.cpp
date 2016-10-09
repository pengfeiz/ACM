#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int num[9],i,m,p;
	while(cin>>num[0]>>num[1]>>num[2]>>num[3]>>num[4]>>num[5]>>num[6]>>num[7]>>num[8])
	{
		m=8;
		p=-1;
		for(i=0;i<9;i++)
		{
			if(num[i]!=0)
				m=i;
			if(num[i]!=0&&p==-1)
				p=i;
		}
		for(i=0;i<9;i++)
		{
			if(num[i]!=0)
			{
				if(i==p)
				{
					if(num[i]<-1||num[i]>1)
						cout<<num[i];
					else if(num[i]==-1)
						cout<<"-";
				}
				else
				{
					if(num[i]<0)
						cout<<"- ";
					else
						cout<<"+ ";
					if(abs(num[i])!=1)
						cout<<abs(num[i]);
				}
				if(i<7)
					cout<<"x^"<<8-i;
				else if(i==7)
					cout<<"x";
				if(i!=m)
					cout<<" ";
			}
		}
		if(m==8&&abs(num[8])==1)
			cout<<"1";
		else if(p==-1)
			cout<<"0";
		cout<<endl;
	}
	return 0;
}

