#include <iostream>

#include <algorithm>
//sort(a,b,±È½Ïº¯Êý)
using namespace std;

int a[10]={1,7,5,8,6,2,3,4,2,1};

bool com(int a,int b)
{return a>b;}


int main()
{
	int i;
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	sort(a,a+10,com);
	//sort(a,a+10);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	system("pause");
	return 0;
}
