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
printf("%d%c",k,s[i]);
k=1;
}
}
printf("\n");
}
return 0;
}