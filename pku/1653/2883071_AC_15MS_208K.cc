#include<stdio.h>
#include<string.h>
const int M=10005;
int num[M];
char temp[M];
int n=0,re;

void get(int cur)
{
	int ct=cur,i,w=0,tt;
	for(i=0;i<n;i++)
	{
		if(ct+num[i]>=cur)
		{
			w++;
			ct=num[i];
		}
		else 
                    ct+=num[i]+1;
	}
	tt=(cur+2)*(w+2);
	if(tt<re)
            re=tt;
}
int main()
{
        int max,i,totel;
	while(scanf("%s",&temp)!=EOF)
	{
		if(temp[0]=='.'||temp[0]==','||temp[0]=='!'||temp[0]=='?')
			num[n-1]++;
		else 
                    num[n++]=strlen(temp);
	}
	re=num[0];
	max=num[0];
	for(i=1;i<n;i++)
	{
		re+=num[i]+1;
		if(num[i]>max)max=num[i];
	}
	totel=re;
	re=(re+2)*3;
	for(i=max;i<totel;i++)
	{
		if(4*(i+2)>re)
                    break;
		get(i);
	}
	printf("%d\n",re);
	return 0;
}
