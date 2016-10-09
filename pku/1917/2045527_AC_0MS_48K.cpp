#include <stdio.h>
#include <string.h>
#define MAX 10000
char a[MAX],b[MAX],c[MAX],d[MAX],e[MAX],x[MAX],y[MAX],h[MAX];
int main()
{
	long i,j,k,m,l;
	scanf("%d",&m);
	getchar();
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
		printf("%s%s%s%s%s\n",a,b,c,d,e);
		l=strlen(y);
		y[l-3]='\0';
		printf("%s%s%s%s%s\n",y,d,c,b,e);
	}
	return 0;
}
