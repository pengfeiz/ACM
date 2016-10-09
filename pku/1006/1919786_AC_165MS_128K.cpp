#include <iostream>
using namespace std;
int main()
{
	int n1,n2,n3,t,year,i=0;
	while(cin>>n1>>n2>>n3>>t&&!(n1==-1&&n2==-1&&n3==-1&&t==-1))
	{
		i++;
		n1=23-n1%23;
		n2=28-n2%28;
		n3=33-n3%33;
		year=33-n3;
		n1+=year;
		n2+=year;
		do{
			n1+=33;
			n2+=33;
			n1%=23;
			n2%=28;
			year+=33;
		}while(n1%23!=0||n2%28!=0);
		year=year-t;
		if(year<0)
			year+=21252;
		else if(year>21252)
			year-=21252;
		cout<<"Case "<<i<<": the next triple peak occurs in "<<year<<" days.\n";
	}
	return 0;
}

