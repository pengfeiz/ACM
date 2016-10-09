#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


int a[10],last[10],n,m;
bool f,e;
queue<int> he[11];


void PlayGame()
{
	int card,p=0,i;
	for(i=0;i<11;i++)
		a[i]=0;
	e=true;
	while(p<=6000)
	{
		for(i=m-1;i>=0;i--)
		{
			if(!he[i].empty())
			{
				a[i]++;
				if(a[i]==14)
					a[i]=1;
				card=he[i].front();
				he[i].pop();
				if(card==a[i])
				{
					p=0;
					last[i]=card;
					he[i+1].push(card);
				}
				 else 
					he[i].push(card);
			}
		}
		p++;
	}
	for(i=0;i<m;i++)
		if(!he[i].empty())
			e=false;
	if(!e)
		f=true;
}


int main()
{
	int x,tim,i;
	freopen("C.dat","r",stdin);
	scanf("%d",&n);
	for(tim=1;tim<=n;tim++)
	{
		scanf("%d",&m);
		for(i=0;i<52;i++)
		{
			scanf("%d",&x);
			he[0].push(x);
		}
		f=false; 
		PlayGame();
		printf("Case %d:",tim);
		if(f)
			printf(" unwinnable\n");
		else
		{
			for(i=0;i<m;i++)
				printf(" %d",last[i]);
			printf("\n");
		}
		for(i=0;i<=m;i++)
			while(!he[i].empty())
				he[i].pop();
	}
	return 0;
}