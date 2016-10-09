#include<iostream>

using namespace std;
int n,m;
char name[10][300];
char s[300];
bool u[10];
bool all,x;

void dosth(char str[])
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp(name[i],str)==0)
		{
			u[i]=true;
			all=false;
			break;
		}
     if(strcmp("beautiful",str)==0||strcmp("pretty",str)==0||strcmp("lovely",str)==0)
	 {
        x=true;
	 }
	 

   
}

int main()
{
	int i,j,l,k,len,kk;
	char str[300];
    bool ll;
//	freopen("in.txt","r",stdin);
   scanf("%d %d",&n,&m);
   len=0;
   getchar();	  
   for(i=0;i<n;i++)
	   gets(name[i]);
   
   for(kk=0;kk<m;kk++)
   {
	   len=0;
	   	memset(u,false,sizeof(u));
	   all=true;
        x=false;
	    gets(s);
		
		
		j=0;
		int length=strlen(s);
		for(i=0;i<length;i++)
		{
			if(s[i]<'a'&&s[i]!=' '&&s[i]!='!')
				s[i]+=32;
			if(s[i]=='!')
				s[i]=' ';
		}
	   for(j=0;j<length;)
	   {
			memset(str,' ',sizeof(str));
			
			   ll=false;
				k=0;
				while(s[j]!=' ')
				{
					str[k]=s[j];
					k++;
					j++;
					ll=true;
				}
				if(ll)
                str[k]='\0';
				if(str[0]!=' ')
				{
				
				  dosth(str);
		            len++;
				}
			j++;	
	   }
			
		
		if(all)
		{
			 
 			if(len<10)
				printf("All: oh\n");
			else
			{
				if(x)
					printf("All: xixi\n");
				else
					printf("All: hehe\n");
			}
		}

       else
	   {
		   if(len<10)
		   {
			   for(i=0;i<n;i++)
			     if(u[i])
				 {
					 printf("%s",name[i]);
					  l=i;
					  break;
				 }
				 for(l=i+1;l<n;l++)
					 if(u[l])
					 {
                        printf(" %s",name[l]);
					 }
				 printf(": oh\n");
		   }

		   else
		   {
			   if(x)
			   {
                   for(i=0;i<n;i++)
			     if(u[i])
				 {
					 printf("%s",name[i]);
					  l=i;
					 break;
				 }
				 for(l=i+1;l<n;l++)
					 if(u[l])
					 {
                        printf(" %s",name[l]);
					 }
				 printf(": xixi\n");
			   }
			   else
			   {
				   for(i=0;i<n;i++)
			     if(u[i])
				 {
					 printf("%s",name[i]);
					  l=i;
					 break;
				 }
				 for(l=i+1;l<n;l++)
					 if(u[l])
					 {
                        printf(" %s",name[l]);
					 }
				 printf(": hehe\n");
			   }

		   }
	   }
		
	   
   }
   return 0;
   
}