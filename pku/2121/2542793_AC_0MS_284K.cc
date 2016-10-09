#include <iostream>
#include <string.h>
using namespace std;

char s[31];
struct gao
{
	int n;
	char s[21];
}a[]={
{0,"zero"}, {1,"one"}, {2,"two"},
{3,"three"}, {4,"four"}, {5,"five"},
{6,"six"}, {7,"seven"}, {8,"eight"},
{9,"nine"}, {10,"ten"}, {11,"eleven"},
{12,"twelve"}, {13,"thirteen"}, {14,"fourteen"},
{15,"fifteen"}, {16,"sixteen"}, {17,"seventeen"},
{18,"eighteen"}, {19,"nineteen"}, {20,"twenty"},
{30,"thirty"}, {40,"forty"}, {50,"fifty"},
{60,"sixty"}, {70,"seventy"}, {80,"eighty"},
{90,"ninety"},{-1,"negative"},{100,"hundred"},
{1000,"thousand"},{1000000,"million"}
};


int main()
{
	int i,n1,n2,n3,b=0;
	char c;
	n1=n2=n3=0;
	while(scanf("%s",s)!=EOF)
	{
		for(i=0;i<32;i++)
			if(strcmp(s,a[i].s)==0)
				break;
		if(i==31)
		{
			n3=n1*a[i].n;
			n1=0;
		}
		else if(i==30)
		{
			n2=n1*a[i].n;
			n1=0;
		}
		else if(i==29)
			n1*=a[i].n;
		else if(i==28)
			b=1;
		else
			n1+=a[i].n;
		if((c=getchar())=='\n')
		{
			if(b)
				printf("-");
			printf("%d\n",n1+n2+n3);
			n1=n2=n3=b=0;
		}
	}
	return 0;
}
