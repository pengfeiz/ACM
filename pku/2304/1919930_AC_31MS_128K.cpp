#include <iostream>
using namespace std;
int main()
{
	int s,n1,n2,n3,tt;
	while(cin>>s>>n1>>n2>>n3&&(n1||n2||n3||s))
	{
		tt=1080;
		if(n1>s)
			tt+=9*(40-n1+s);
		else
			tt+=9*(s-n1);
		if(n2>n1)
			tt+=9*(n2-n1);
		else
			tt+=9*(40-n1+n2);
		if(n3>n2)
			tt+=9*(40-n3+n2);
		else
			tt+=9*(n2-n3);
		cout<<tt<<endl;
	}
	return 0;
}

		