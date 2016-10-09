#include <iostream>
using namespace std;
int main()
{
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	if(n1<168)
		cout<<"CRASH "<<n1;
	else if(n2<168)
		cout<<"CRASH "<<n2;
	else if(n3<168)
		cout<<"CRASH "<<n3;
	else
		cout<<"NO CARSH";
	cout<<endl;
	return 0;
}