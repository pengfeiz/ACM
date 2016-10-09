#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[8][40],c[40];
	int num1[20][3],n1,n2,i,j,num2[20][3],p;
	for(i=0;i<8;i++)
		cin>>c>>s[i];
	cin>>c;
	n1=n2=0;
	for(i=0;i<8;i++)
		for(j=2;j<33;j+=4)
		{
			if(s[i][j]=='k')
			{
				num1[n1][0]=6;
				num1[n1][1]=i;
				num1[n1][2]=(j-2)/4;
				n1++;
			}
			else if(s[i][j]=='q')
			{
				num1[n1][0]=5;
				num1[n1][1]=i;
				num1[n1][2]=(j-2)/4;
				n1++;
			}
			else if(s[i][j]=='r')
			{
				num1[n1][0]=4;
				num1[n1][1]=i;
				num1[n1][2]=(j-2)/4;
				n1++;
			}
			else if(s[i][j]=='b')
			{
				num1[n1][0]=3;
				num1[n1][1]=i;
				num1[n1][2]=(j-2)/4;
				n1++;
			}
			else if(s[i][j]=='n')
			{
				num1[n1][0]=2;
				num1[n1][1]=i;
				num1[n1][2]=(j-2)/4;
				n1++;
			}
			else if(s[i][j]=='p')
			{
				num1[n1][0]=1;
				num1[n1][1]=i;
				num1[n1][2]=(j-2)/4;
				n1++;
			}
			else if(s[i][j]=='K')
			{
				num2[n2][0]=6;
				num2[n2][1]=i;
				num2[n2][2]=(j-2)/4;
				n2++;
			}
			else if(s[i][j]=='Q')
			{
				num2[n2][0]=5;
				num2[n2][1]=i;
				num2[n2][2]=(j-2)/4;
				n2++;
			}
			else if(s[i][j]=='R')
			{
				num2[n2][0]=4;
				num2[n2][1]=i;
				num2[n2][2]=(j-2)/4;
				n2++;
			}
			else if(s[i][j]=='B')
			{
				num2[n2][0]=3;
				num2[n2][1]=i;
				num2[n2][2]=(j-2)/4;
				n2++;
			}			
			else if(s[i][j]=='N')
			{
				num2[n2][0]=2;
				num2[n2][1]=i;
				num2[n2][2]=(j-2)/4;
				n2++;
			}
			else if(s[i][j]=='P')
			{
				num2[n2][0]=1;
				num2[n2][1]=i;
				num2[n2][2]=(j-2)/4;
				n2++;
			}
		}
	for(i=0;i<n1-1;i++)
		for(j=i+1;j<n1;j++)
		{
			if(num1[i][0]<num1[j][0])
			{
				p=num1[i][0];
				num1[i][0]=num1[j][0];
				num1[j][0]=p;
				p=num1[i][1];
				num1[i][1]=num1[j][1];
				num1[j][1]=p;
				p=num1[i][2];
				num1[i][2]=num1[j][2];
				num1[j][2]=p;
			}
			else if(num1[i][0]==num1[j][0]&&num1[i][1]>num1[j][1])
			{
				p=num1[i][0];
				num1[i][0]=num1[j][0];
				num1[j][0]=p;
				p=num1[i][1];
				num1[i][1]=num1[j][1];
				num1[j][1]=p;
				p=num1[i][2];
				num1[i][2]=num1[j][2];
				num1[j][2]=p;
			}
			else if(num1[i][0]==num1[j][0]&&num1[i][1]==num1[j][1]&&num1[i][2]>num1[j][2])
			{
				p=num1[i][0];
				num1[i][0]=num1[j][0];
				num1[j][0]=p;
				p=num1[i][1];
				num1[i][1]=num1[j][1];
				num1[j][1]=p;
				p=num1[i][2];
				num1[i][2]=num1[j][2];
				num1[j][2]=p;
			}
		}
	for(i=0;i<n1-1;i++)
		for(j=i+1;j<n1;j++)
		{
			if(num2[i][0]<num2[j][0])
			{
				p=num2[i][0];
				num2[i][0]=num2[j][0];
				num2[j][0]=p;
				p=num2[i][1];
				num2[i][1]=num2[j][1];
				num2[j][1]=p;
				p=num2[i][2];
				num2[i][2]=num2[j][2];
				num2[j][2]=p;
			}
			else if(num2[i][0]==num2[j][0]&&num2[i][1]<num2[j][1])
			{
				p=num2[i][0];
				num2[i][0]=num2[j][0];
				num2[j][0]=p;
				p=num2[i][1];
				num2[i][1]=num2[j][1];
				num2[j][1]=p;
				p=num2[i][2];
				num2[i][2]=num2[j][2];
				num2[j][2]=p;
			}
			else if(num2[i][0]==num2[j][0]&&num2[i][1]==num2[j][1]&&num2[i][2]>num2[j][2])
			{
				p=num2[i][0];
				num2[i][0]=num2[j][0];
				num2[j][0]=p;
				p=num2[i][1];
				num2[i][1]=num2[j][1];
				num2[j][1]=p;
				p=num2[i][2];
				num2[i][2]=num2[j][2];
				num2[j][2]=p;
			}
		}
		cout<<"White: ";
	for(i=0;i<n2;i++)
	{
		if(i)
			cout<<",";
		if(num2[i][0]==6)
			cout<<"K";
		else if(num2[i][0]==5)
			cout<<"Q";
		else if(num2[i][0]==4)
			cout<<"R";
		else if(num2[i][0]==3)
			cout<<"B";
		else if(num2[i][0]==2)
			cout<<"N";
		cout<<char(num2[i][2]+'a')<<8-num2[i][1];
	}
	cout<<endl;
	cout<<"Black: ";
	for(i=0;i<n1;i++)
	{
		if(i)
			cout<<",";
		if(num1[i][0]==6)
			cout<<"K";
		else if(num1[i][0]==5)
			cout<<"Q";
		else if(num1[i][0]==4)
			cout<<"R";
		else if(num1[i][0]==3)
			cout<<"B";
		else if(num1[i][0]==2)
			cout<<"N";
		cout<<char(num1[i][2]+'a')<<8-num1[i][1];
	}
	cout<<endl;
	return 0;
}

			


		
