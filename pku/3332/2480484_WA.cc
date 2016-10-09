#include <iostream>
using namespace std;
#define MAX 1001

char s[MAX];


int main()
{
	int t,i,l;
	bool f,f1,f2,coun,ee,qq;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		f=f1=f2=coun=ee=true;
		gets(s);
		l=strlen(s);
		for(i=0;i<l&&s[i]==' ';i++);
		l--;
		for(l;l>=0&&s[l]==' ';l--);
		l++;
		s[l]='\0';
		if(s[i]=='+'||s[i]=='-')
			i++;
		for(i;i<l;i++)
		{
			if(s[i]=='.')
			{
				if(!coun)
				{
					f=false;
					break;
				}
				coun=false;
				if(f1)
				{
					f=false;
					break;
				}
			}
			else if(s[i]=='e'||s[i]=='E')
			{
				if(coun||f1||f2)
				{
					f=false;
					break;
				}
				else
				{
					i++;
					if(s[i]=='-'||s[i]=='+')
						i++;
					for(i;i<l;i++)
					{
						if(s[i]<='9'&&s[i]>='0')
							ee=false;
						else
							break;
					}
					if(i<l||ee)
					{
						f=false;
						break;
					}
				}
			}
			else if(s[i]<='9'&&s[i]>='0')
			{
				if(coun)
					f1=false;
				else
					f2=false;
			}
			else
			{
				f=false;
				break;
			}
		}
		if(!coun)
		{
			if(f1||f2)
				f=false;
		}
		if(!f)
			printf("ILLEGAL\n");
		else
			printf("LEGAL\n");
	}
	return 0;
}

