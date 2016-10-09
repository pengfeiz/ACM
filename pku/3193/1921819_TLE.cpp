#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
void qsort(char a[][100],int l, int r)             //对字典进行排序
{
	int i, j, mid;
	char temp[100];
	i = l; j = r; mid = (l + r) / 2;
	do
	{
		while (strcmp(a[i] , a[mid])<0)i++;
		while (strcmp(a[j] , a[mid])>0)j--;
		if (i <= j)
		{	
			strcpy(temp , a[i]);
			strcpy(a[i] , a[j]);
			strcpy(a[j] , temp);
			i++; j--;
		}
	} while (i <= j);
	if (l < j) qsort(a,l, j);
	if (i < r) qsort(a,i, r);
}
int main()
{
	char s[1010][100],s1[100];    //s存放字典
	int m,n,i,j,k,sum=0;
	scanf("%d%d\n",&n,&m);
	for(i=0;i<n;i++) gets(s[i]);     //输入字典
	qsort(s,0,n-1);
	for(i=0;i<m;i++)
	{
		gets(s1);                      
		j=0,k=n-1;
		while(j<k)               // 二分查找，确定串所在小区间位置
		{
			int mid=(j+k)/2;
			if(strcmp(s[mid],s1) < 0) j=mid;
			else k=mid;
		}
		for(int t=j;t<=k;t++)
			if(strstr(s[t],s1)==s[t]) {sum++; break;}
	}
	printf("%d\n",sum);
	return 0;
}
