#include<iostream>
using namespace std;
#define Max 15001
int f[Max];
int n;
int main()
{
  int i;
  f[0]=0;
  f[1]=1;
  for(i=2;i<Max;i++)
	  f[i]=(f[i-1]+f[i-2])%10000;
  while(cin>>n)
  {
	  if(n==-1)
		  break;
	  cout<<f[n%15000]<<endl;
  }
 return 0;
}