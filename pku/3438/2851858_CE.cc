#include <iostream>
using namespace std;


char s[1001];

int main()
{
int t,i,l,k;
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
return 0;
}