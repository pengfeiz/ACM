#include <iostream>
using namespace std;
int main()
{
	char c[2],s[2];
	int x1,x2,y1,y2,nn,x,y;
	cin>>nn;
	while(nn-->0)
	{
		cin>>c>>s;
		x1=c[0]-'a';
		y1=c[1]-'1';
		x2=s[0]-'a';
		y2=s[1]-'1';
		x=x2-x1;
		y=y2-y1;
		if(abs(x)>abs(y))
			cout<<abs(x)<<" ";
		else
			cout<<abs(y)<<" ";
		if(x==y&&y==0)
			cout<<"0 ";
		else if(x==y||x==0||y==0)
			cout<<"1 ";
		else 
			cout<<"2 ";
		if(x==0&&y==0)
			cout<<0<<" ";
		else if(x==0||y==0)
			cout<<"1 ";
		else
			cout<<"2 ";
		if(x==y&&y==0)
			cout<<"0\n";
		else if(abs(x)==abs(y))
			cout<<"1\n";
		else if(abs(x)%2==abs(y)%2)
			cout<<"2\n";
		else cout<<"Inf\n";
	}
	return 0;
}

