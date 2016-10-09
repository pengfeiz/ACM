#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <math.h>
int main()
{
	char s[101][61],c[61];
	int nn,i,j,l,r;
	double n;
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
		r=62/(l+2);
		n=double(nn);
		n=ceil(n/(double)r);
		for(i=0;i<(int)n;i++)
		{
			for(j=0;j<r;j++)
			{
				if(i+(j+1)*(int)n>=nn)
				{
					cout<<s[i+j*(int)n]<<endl;
					break;
				}
				else
					cout<<setiosflags(ios::left)<<setw(l+2)<<setfill(' ')<<s[i+j*(int)n];
			}
		}
	}
	return 0;
}


