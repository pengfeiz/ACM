#include <stdio.h>
#include <search.h>
#include <string.h>
#include <stdlib.h>
int stick[100000][2],index[100000];
int sort_function(const void *a,const void *b)
{
	if(stick[*(int*)a][0]>stick[*(int*)b][0])return 1;
	else if(stick[*(int*)a][0]==stick[*(int*)b][0]&&stick[*(int*)a][1]<stick[*(int*)b][1])return 1;
	else return -1;
}

int main()
{
	int n,m,i,num=0,real,max=-1;
	int mid=0,end=-1,p;
	char str[1000000];
	scanf("%d",&m);
	n=0;
	str[0]='\0';
	while(1)
	{
		    int ex;
        	scanf("%d %d",&stick[n][0],&stick[n][1]);
        	if(stick[n][0]==0&&stick[n][1]==0)break;
       		if(stick[n][0]>stick[n][1])
       		{
       	       	 	ex=stick[n][0];
                	stick[n][0]=stick[n][1];
                	stick[n][1]=ex;
                
        	}    
        	index[n]=n;
        	n++;
	}
	qsort(index,n,sizeof(int),sort_function);
	for(i=0;i<n;i++)
	{
		if(max>=m)break;
		if(mid>=stick[index[i]][0]&&mid<=stick[index[i]][1])
		{
			if(stick[index[i]][1]>end)
			{
				real=1;
				end=stick[index[i]][1];
				p=index[i];
			}
		}
		else if(end!=-1)
		{
			mid=end;
			end=-1;
			real=0;
			sprintf(str+strlen(str),"%d %d\n",stick[p][0],stick[p][1]);
			num++;
			if(max==-1||stick[p][1]>max)max=stick[p][1];
			if(mid>=stick[index[i]][0]&&mid<=stick[index[i]][1])
			{

					end=stick[index[i]][1];
					p=index[i];
					real=1;
			}
		}
	}
	if(real)
	{
		sprintf(str+strlen(str),"%d %d\n",stick[p][0],stick[p][1]);
		if(max==-1||max<stick[p][1])max=stick[p][1];
	}
	if(max<m)printf("No solution\n");
    	else
    	{
		printf("%d\n",num+1);
		printf("%s",str);
    	}

    	return 0;
}
