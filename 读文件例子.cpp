#include<iostream>
#define M 10
#define N 6
using namespace std ;

int main(){
	
	int n;
	int j=0;
	scanf("%d",n);
	char ss[M];
	memset(ss,'#',M);
	freopen("A.txt","r",stdin);
	int x;
	for(x=0;x<M;x++)
		printf("%d\t",x);
		printf("\n");
	for(x=0;x<M;x++)
		printf("%c\t",ss[x]);
		printf("\n");
	while(gets(ss)){	
		for(int i=0;i<M;i++){
			if(*(ss+i) == '\t')
				printf("\\t\t");
			else if(*(ss+i) == '\0')
				printf("\\0\t");
			else
			printf("%c\t",*(ss+i));
	
		}
		printf("\n");
		j++;
		
	}
		printf("jÊÇ%d",j);
	

		

	fclose(stdin);
	freopen("CON","r",stdin);

	system("pause");
	return 0;
}
