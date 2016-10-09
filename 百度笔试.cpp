#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
struct record{
	char str[15];
	int  poss;
};

int outputselect(int n,int *a,int length)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(n<a[i])
				return i;
	}
}

void input(char *buf,struct record* input)
{
	int i=0;
	while(buf[i]!='\t')
	{
		(*input).str[i]=buf[i];
		i++;
	}
	(*input).str[i]='\0';
	i++;
	(*input).poss = atoi(&buf[i]);
	return;
}

int main(void)
{
	struct record a[6];
	int n,sum=0,i=0,pos[6],length=0;
	
	
	scanf("%d",&n);
	char buf[50]="\0";
	FILE *fp;
	if((fp = fopen("A.txt","r")) == NULL)
	{
		printf("file openerror!\n");
		exit(-1);
	}
	while( fgets(buf,50,fp) != NULL )
	{
		input(buf,&a[i]);
		if( i == 0)
			pos[i] = a[i].poss;
		else
			pos[i] = pos[i-1] + a[i].poss;
			
		sum = sum + a[i].poss;
		i++;
	}
	length=i;
	if(sum != 100)
	{
		printf("possible sum is not 100,file error!,%d\n",sum);
		exit(-1);
	}
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		int select = outputselect(rand()%100,pos,length);  

for(i=0;i<n;i++)
	{
		int select = outputselect(rand()%100,pos,length);
		printf("%s\n",a[select].str);
	}
	system("pause");
	return 0;
	
}   
}
