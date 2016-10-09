#include <iostream>
using namespace std;
#define MAX 50
int main()
{
	int i,l,n[MAX],t=0,tt,t2;
	while(cin>>l&&l!=0)
	{
		t++;
		tt=t2=0;
		for(i=0;i<l;i++)
		{
			cin>>n[i];
			tt+=n[i];
		}
		tt=tt/l;
		for(i=0;i<l;i++)
			if(n[i]>tt)
				t2+=n[i]-tt;
		cout<<"Set #"<<t<<endl;
		cout<<"The minimum number of moves is "<<t2<<".\n\n";
	}
	return 0;
}
