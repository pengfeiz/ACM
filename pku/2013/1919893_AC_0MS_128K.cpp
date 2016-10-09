#include <iostream>
using namespace std;
char s[20][30];
int main()
{
	int n,i,t=0;
	while(cin>>n&&n!=0)
	{
		t++;
		cout<<"SET "<<t<<endl;
		for(i=0;i<n;i++)
			cin>>s[i];
		for(i=0;i<n;i+=2)
			cout<<s[i]<<endl;
		for(i=n-1-n%2;i>0;i-=2)
			cout<<s[i]<<endl;
	}
	return 0;
}

