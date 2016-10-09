#include <iostream>
char ss[101];
int a,c,e,n,k,b[5];
using namespace std;


int main()
{
	int l,i,tt,qq;
	bool ff;
	while(scanf("%s",ss),strcmp(ss,"0"))
	{
		ff=false;
		a=c=e=n=k=tt=qq=0;
		memset(b,0,sizeof(b));
		l=strlen(ss);
		for(i=0;i<l;i++)
		{
			if(ss[i]>='a')
			{
				b[ss[i]-'p']++;
				ff=true;
				tt++;
			}
			else if(ss[i]=='A')
			{
				qq++;
				a++;
			}
			else if(ss[i]=='C')	
			{
				qq++;
				c++;
			}
			else if(ss[i]=='E')			
			{
				qq++;
				e++;
			}	
			else if(ss[i]=='N')
				n++;
			else if(ss[i]=='K')			
			{
				qq++;
				k++;
			}	
		}
		if(!ff)
		{
			printf("no WFF possible\n");
			continue;
		}
		else
		{
			ff=true;
			while(n--)
				printf("N");
			for(i=0;ff&&i<5;i++)
			{
				while(b[i]&&ff)
				{
					if(tt==1||qq==0)
					{
						printf("%c",i+'p');
						b[i]--;
						ff=false;
					}
					else if(a)
					{
						printf("A");
						a--;
						printf("%c",i+'p');
						b[i]--;
						tt--;
						qq--;
					}
					else if(c)
					{
						printf("C");
						c--;
						printf("%c",i+'p');
						b[i]--;
						tt--;
						qq--;
					}
					else if(e)
					{
						printf("E");
						e--;
						printf("%c",i+'p');
						b[i]--;
						tt--;
						qq--;
					}
					else if(k)
					{
						printf("K");
						k--;
						printf("%c",i+'p');
						b[i]--;
						tt--;
						qq--;
					}
					else
					{
						ff=false;
						break;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}




