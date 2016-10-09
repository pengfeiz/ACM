#include <iostream>
using namespace std;


char s[1003];

int main()
{
int t,i,l,k,q=0;
scanf("%d",&t);
while(t--)
{
k=1;
scanf("%s",s);
l=strlen(s);
for(i=0;i<l;i++)
{
if(s[i]==s[i+1])
k++;
else
{
printf("%d%c\n",k,s[i]);
k=1;
}
}
if(t!=0)
printf("\n");
}
return 0;
}