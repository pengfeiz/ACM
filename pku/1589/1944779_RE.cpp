#include <iostream.h>
#include <iomanip.h>
#include <string.h>
int main()
{
	char s[100][60],c[60];
	int nn,i,j,l,r;
	while(cin>>nn)
	{
		l=0;
		for(i=0;i<nn;i++)
		{
			cin>>s[i];
			if(l<(int)strlen(s[i]))
				l=strlen(s[i]);
		}
		for(i=0;i<60;i++)
			cout<<"-";
		cout<<endl;
		for(i=0;i<nn-1;i++)
			for(j=i+1;j<nn;j++)
				if(strcmp(s[i],s[j])>0)
				{
					strcpy(c,s[i]);
					strcpy(s[i],s[j]);
					strcpy(s[j],c);
				}
		r=60/(l+2);
		for(i=0;i<=nn/r;i++)
		{
			for(j=0;j<r&&i*nn/r+j<nn;j++)
				cout<<setiosflags(ios::left)<<setw(l+2)<<setfill(' ')<<s[i*nn/r+j];
			cout<<endl;
		}
	}
	return 0;
}


