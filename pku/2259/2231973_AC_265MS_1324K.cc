#include <stdio.h>
#include <string.h>
#define MAX1 1024
#define MAX2 1048576

int kase=0;
int n;
int team[MAX2];
int teama[MAX1];
int teamb[MAX1];
int queue[MAX1][MAX1];
int queuea[MAX1];
int queueb[MAX1];
int head,tail;

int read()
{
	int i,j,m,elmt;
	scanf("%d",&n);
	if(n==0)
		return 0;
	for(i=0;i<n;i++)
    {
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			scanf("%d",&elmt);
			team[elmt]=i;
		}
    }
	return 1;
}

void enqueue(int element)
{
	int t,pos;
	t=team[element];
	if(teamb[t]==0)
    {
		queue[tail][0]=element;
		queuea[tail]=0;
		queueb[tail]=1;
		teama[t]=tail;
		teamb[t]=1;
		tail=(tail+1)%MAX1;
    }
	else 
    {
		pos=teama[t];
		queue[pos][queueb[pos]] = element;
		queueb[pos]=(queueb[pos]+1)%MAX1;
		teamb[t]++;
    }
}

int dequeue()
{
	int element=queue[head][queuea[head]];
	int t=team[element];
	queuea[head]=(queuea[head]+1)%MAX1;
	teamb[t]--;
	if(teamb[t]==0)
		head=(head+1)%MAX1;
	return element;
}

void solve()
{
	char cmd[30];
	int element,t;
	head=tail=0;
	for(t=0;t<n;t++)
		teamb[t]=0;
	printf("Scenario #%d\n",++kase);
	while(1)
    {
		scanf("%s",cmd);
		if(strcmp(cmd,"ENQUEUE")==0)
		{
			scanf("%d",&element);
			enqueue(element);
		}
		else if (strcmp(cmd,"DEQUEUE")==0)
			printf("%d\n",dequeue());
		else if (strcmp(cmd,"STOP")==0)
		{
			printf("\n");
			return;
		}
    }
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(read())
		solve();
	return 0;
}
