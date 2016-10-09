#include <stdio.h>
#include <string.h>
int main()
{
	long i,j,k,m,l;
	char a[500],b[500],c[500],d[500],e[500],x[500],y[500],h[500];
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
