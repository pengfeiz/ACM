#include<stdio.h>
#include<string.h>
int main()
{
	char s[8];
	int n,len,sum,k,i,j,l=0,kk;
	int num[7]={9,7,3,9,7,3,9};
	scanf("%d",&n);
	while(n--)
	{
		l++;
		sum=0;
		scanf("%s",&s);
		len=strlen(s);
		
		
			for(i=len-1,j=6;i>=0;i--,j--)
			{
				if(s[i]=='?')
				{   
					k=i;
				}
				else
				{
					sum+=(s[i]-'0')*num[j];
				
				}
			}
		kk=10-sum%10;
		if(kk==10)
			s[k]='0';
		else
		{
			for(i=1;i<=9;i++)
				if((i*num[7-len+k])%10==kk)
					break;
			s[k]=i+'0';
		}
			printf("Scenario #%d:\n",l);
		printf("%s\n",s);
		printf("\n");
	}
	return 0;
}