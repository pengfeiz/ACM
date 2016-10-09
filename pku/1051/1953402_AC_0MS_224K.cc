#include <iostream.h>
#include <string>
using namespace std;
char letter[30]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','_','.',',','?'};
string code[30]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-", 
".-.", "..." ,"-", "..-" ,"...-", ".--", "-..-" ,"-.--" ,"--.." ,"..--","---.",".-.-","----"};
int info[30]={2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,4,3,3,1,3,4,3,4,4,4,4,4,4,4};
void fmat(char *mes,int len)
{
	int Info[100];
	string tem,tem1;
	string Co;
	int i,sum=0;
	int p;
	for(i=0;i<len;i++)
	{
		if(mes[i]>='A'&&mes[i]<='Z')
		{	
			Co.append(code[mes[i]-'A']);
		    Info[i]=info[mes[i]-'A'];
		}
		else
		{
			for(int t=26;t<30;t++)
			{
				if(mes[i]==letter[t])
				{
					Co.append(code[t]);
					Info[i]=info[t];
				}
			}
		}
	}
	i--;
	for(;i>=0;i--)
	{
		p=sum;
		sum+=Info[i];
		int io=Info[i];
		tem.assign(Co,p,io);
		for(int j=0;j<30;j++)
		{
			if(tem==code[j])
			{
				cout<<letter[j];
				break;
			}
		}
		tem=tem1;
	}
	cout<<endl;
}
int main()
{
	int num,len;
	char mes[400];
	cin>>num;	
	for(int i=1;i<=num;i++)
	{
		cin>>mes;
		len=strlen(mes);
		cout<<i<<": ";
		fmat(mes,len);
	}
	return 0;
}
