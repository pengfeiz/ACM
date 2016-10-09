#include <iostream>
using namespace std;
void pri()
{	
	for(int i=0;i<33;i++)
	{
		if(i%4==0)
			cout<<"+";
		else
			cout<<"-";
	}
	cout<<endl;
}
int main()
{
	char s1[200],s2[200];
	int i,j,l1,l2,num[8][8]={{0}};
	gets(s1);
	gets(s2);
	l1=strlen(s1);
	l2=strlen(s2);
	for(i=7;i<l1;i++)
	{
		if(s1[i]==',')
			continue;
		else if(s1[i]=='K')
		{
			num[s1[i+1]-'a']['8'-s1[i+2]]=6;
			i+=3;
		}
		else if(s1[i]=='Q')
		{
			num[s1[i+1]-'a']['8'-s1[i+2]]=5;
			i+=3;
		}
		else if(s1[i]=='R')
		{
			num[s1[i+1]-'a']['8'-s1[i+2]]=4;
			i+=3;
		}
		else if(s1[i]=='B')
		{
			num[s1[i+1]-'a']['8'-s1[i+2]]=3;
			i+=3;
		}		
		else if(s1[i]=='N')
		{
			num[s1[i+1]-'a']['8'-s1[i+2]]=2;
			i+=3;
		}
		else
		{
			num[s1[i]-'a']['8'-s1[i+1]]=1;
			i+=2;
		}
	}
	for(i=7;i<l2;i++)
	{
		if(s2[i]==',')
			continue;
		else if(s2[i]=='K')
		{
			num[s2[i+1]-'a']['8'-s2[i+2]]=12;
			i+=3;
		}
		else if(s2[i]=='Q')
		{
			num[s2[i+1]-'a']['8'-s2[i+2]]=11;
			i+=3;
		}
		else if(s2[i]=='R')
		{
			num[s2[i+1]-'a']['8'-s2[i+2]]=10;
			i+=3;
		}
		else if(s2[i]=='B')
		{
			num[s2[i+1]-'a']['8'-s2[i+2]]=9;
			i+=3;
		}		
		else if(s2[i]=='N')
		{
			num[s2[i+1]-'a']['8'-s2[i+2]]=8;
			i+=3;
		}
		else
		{
			num[s2[i]-'a']['8'-s2[i+1]]=7;
			i+=2;
		}
	}
	for(i=0;i<8;i++)
	{
		pri();
		for(j=0;j<33;j++)
		{
			if(j%4==0)
				cout<<"|";
			else if(j%4==1||j%4==3)
			{
				if((i+j/4)%2==0)
					cout<<".";
				else
					cout<<":";
			}
			else if(j%4==2)
			{
				if(num[(j-2)/4][i]==6)
					cout<<"K";
				else if(num[(j-2)/4][i]==5)
					cout<<"Q";
				else if(num[(j-2)/4][i]==4)
					cout<<"R";
				else if(num[(j-2)/4][i]==3)
					cout<<"B";
				else if(num[(j-2)/4][i]==2)
					cout<<"N";
				else if(num[(j-2)/4][i]==1)
					cout<<"P";
				else if(num[(j-2)/4][i]==12)
					cout<<"k";
				else if(num[(j-2)/4][i]==11)
					cout<<"q";
				else if(num[(j-2)/4][i]==10)
					cout<<"r";
				else if(num[(j-2)/4][i]==9)
					cout<<"b";
				else if(num[(j-2)/4][i]==8)
					cout<<"n";
				else if(num[(j-2)/4][i]==7)
					cout<<"p";
				else if((i+j/4)%2==0)
					cout<<".";
				else cout<<":";
			}
		}
		cout<<endl;
	}
	pri();
	return 0;
}



			
	