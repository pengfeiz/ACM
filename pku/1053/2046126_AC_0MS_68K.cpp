#include <iostream>
using namespace std;
char s[1000][5],c;
bool judge(int i,int j,int k)
{
	int w;
	for(w=0;w<4;w++)
		if(!((s[i][w]==s[j][w]&&s[j][w]==s[k][w])||(s[i][w]!=s[j][w]&&s[j][w]!=s[k][w]&&s[i][w]!=s[k][w])))
			return false;
	return true;
}
int main()
{
	int n=0,i,j,k,t;
	while(cin)
	{
		n=0;
		cin.getline(s[n],100);
		while(strlen(s[n++])==4)
			cin.getline(s[n],100);
		n--;
		printf("CARDS: ");
		for(i=0;i<n;i++)
			printf(" %s",s[i]);
		printf("\n");
		t=0;
		printf("SETS:   ");
		for(i=0;i<n-2;i++)
			for(j=i+1;j<n-1;j++)
				for(k=j+1;k<n;k++)
					if(judge(i,j,k))
					{
						if(t)
							printf("        ");
						printf("%d.  %s %s %s\n",++t,s[i],s[j],s[k]);
					}
		if(!t)
			printf("*** None Found ***\n");
		printf("\n");
	}
	return 0;
}


