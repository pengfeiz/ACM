#include <stdio.h>
#include <string.h>
int main()
{
    char a[110],b[110];
    int k,i,j,jin;
    for(i=0;i<110;i++)
		*(a+i)=48;
    while(scanf("%s",b)&&strcmp(b,"0")!=0)
    {
        k=strlen(b);
        j=109;
		jin=0;
        for(i=109;i>=0;i--)
        {
            if(k>0)
            {
                *(a+i)=*(a+i)+*(b+k-1)+jin-48;
                k--;
            }
			else if(k==0)
				*(a+i)=*(a+i)+jin;
            if(*(a+i)>=58)
            {
                *(a+i)=*(a+i)-10;
                jin=1;
            }
            else jin=0;
        }
    }
	for(i=0,jin=0;i<110;i++)
	{
		if(jin==0&&a[i]=='0')
			continue;
		else if(a[i]!=0)
			jin=1;
		printf("%c",a[i]);
	}
	printf("\n");
    return 0;
}