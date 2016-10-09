#include <stdio.h>
#include <string.h>
#define MAX 10000
char a[MAX],b[MAX],c[MAX],d[MAX],e[MAX],x[MAX],y[MAX],h[MAX];
int main()
{
	long i,j,k,m,l;
	scanf("%d",&m);
	for(j=0;j<m;j++)
	{
		gets(x);
		gets(y);
		k=i=0;
		while(x[i++]!='<')
			a[k++]=x[i-1];
		a[k]='\0';
		k=0;
		while(x[i++]!='>')
			b[k++]=x[i-1];
		b[k]='\0';
		k=0;
		while(x[i++]!='<')
			c[k++]=x[i-1];
		c[k]='\0';
		k=0;
		while(x[i++]!='>')
			d[k++]=x[i-1];
		d[k]='\0';
		k=0;
		while(x[i++]!='\0')
			e[k++]=x[i-1];
		e[k]='\0';
		strcpy(h,a);
		strcat(h,b);
		strcat(h,c);
		strcat(h,d);
		strcat(h,e);
		printf("%s\n",h);
		l=strlen(y);
		y[l-3]='\0';
		strcat(y,d);
		strcat(y,c);
		strcat(y,b);
		strcat(y,e);
		printf("%s\n",y);
	}
	return 0;
}
