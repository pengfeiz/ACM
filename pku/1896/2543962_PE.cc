#include <iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,j;
	bool t,p;
	char c;
	n=0;
	t=p=false;
	while(scanf("%c",&c)!=EOF)
	{
		if(c==' '||c=='\n')
			continue;
		if(c=='{')
		{
			n+=4;
			if(t)
				printf(" ");
			printf("{\n");
			for(j=0;j<n;j++)
				printf(" ");
			t=1;
		}
		else if(c==';')
		{
			printf(";\n");
			for(j=0;j<n-4;j++)
				printf(" ");
			p=true;
		}
		else if(c==',')
			printf(", ");
		else if(c=='}')
		{
			n-=4;
			printf("}");
			p=false;
		}
		else
		{
			if(p)
				for(j=0;j<4;j++)
					printf(" ");
			p=false;
			printf("%c",c);
		}
	}
	printf("\n");
	return 0;
}

		