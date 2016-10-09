#include<iostream>
using namespace std;
long int a[2000];
int money[]={0,1,2,5,10,20,50,100};

int main()
{
	
	     long int n,i,j;
			a[0]=1;
	        for(i=1;i<8;i++)
			{
				for(j=0;j+money[i]<2000;j++)
					a[j+money[i]]+=a[j];
			}
	   
          while(cin>>n)
		  {
			  cout<<a[n]<<endl;
		  }
	
	return 0;
}