#include <string>
#include <iostream>
using namespace std;
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
string menu[7]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int main()
{
	long m,n,nmyear,nmmon,nmday,i;
	while(cin>>m&&m!=-1)
	{
		nmyear=2000;nmmon=0;nmday=0;
		n=m;
		while(true)
		{
			int flag=1;
			if(((nmyear%4==0&&nmyear%100!=0)||(nmyear%400==0))&&n>=366) 
			{
				flag=0;
				nmyear++;
				n-=366;
			}
			else if(!((nmyear%4==0&&nmyear%100!=0)||(nmyear%400==0))&&n>=365) 
			{
				flag=0;
				nmyear++;
				n-=365;
			}
			if(flag)
				break;
		}
 		if((nmyear%4==0&&nmyear%100!=0)||(nmyear%400==0))
			month[1]=29;
		else 
			month[1]=28;
		for(i=0;i<12;i++)
		{
			if(n>=month[i]) 
			{
				nmmon++;
				n-=month[i];
			}
			else break;
		}
		nmday=n;
		cout<<nmyear<<'-';
		if(nmmon+1<10) 
			cout<<'0'<<nmmon+1<<'-';
		else 
			cout<<nmmon+1<<'-';
		if(nmday+1<10) 
			cout<<'0'<<nmday+1<<' ';
		else 
			cout<<nmday+1<<' ';
		cout<<menu[m%7]<<endl;
	}
	return 0;
}