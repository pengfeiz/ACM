#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	while(n--)
	{
		cin>>i>>j;
		if(i>=j)
			cout<<"MMM BRAINS"<<endl;
		else
			cout<<"NO BRAINS"<<endl;
	}
	return 0;
}