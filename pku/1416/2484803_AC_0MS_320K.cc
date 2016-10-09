#include<iostream>
using namespace std; 
#define Max 50
int n,t,k;
int record[Max],bina[Max];

void dfs(char *p,int sum,int re)
{
   if(*p==0)
   {
      record[k]=sum;
	  bina[k++]=re;
	  return ;
   }
   int m=*p-'0';
   while(*p)
   {
	   p++;
	  
	   re=re<<1;
	   dfs(p,sum+m,re+1);
	   m=m*10+(*p)-'0';
   }
}
int main()
{
	char s[10];
	int i,ans,ansi;
	bool u=false;
	while(scanf("%d%d",&t,&n),n||t)
	{
		ltoa(n,s,10);
		k=0;
		dfs(s,0,0);
		ans=-1;
		for(i=0;i<k;i++)
		{
			if(record[i]==ans)
				u=true;
			else if(record[i]>ans&&record[i]<=t)
			{
				u=false;
				ans=record[i];
				ansi=i;
			}
		}
		if(ans==-1)
			cout<<"error"<<endl;
        else if(u)
			cout<<"rejected"<<endl;
		else
		{
			cout<<ans<<" ";
			int len=strlen(s);
			for(i=0;i<len;i++)
			{
				cout<<s[i];
				if((bina[ansi]>>(len-i-1))&1)
					cout<<" ";
			}
			cout<<endl;
		}		
	}
	return 0;
}
