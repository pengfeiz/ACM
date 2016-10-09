#include <algorithm>

using namespace std;

const int seq[25][2] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {2, 0}, {3, 0}, {4, 0},
{1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 1}, {3, 1}, {4, 1}, {2, 2}, {2, 3}, {2, 4}, {3, 2}, {4, 2},
{3, 3}, {3, 4}, {4, 3}, {4, 4}};
const int pow[5] = {10000, 1000, 100, 10, 1};

bool hash[100000];
int grid[5][5];
int sum, first;

struct Answer
{
	int grid[5][5];
}ans[100];
int top;
int sumrow[5], sumcol[5];

int checksum(int n)
{
	int s=0;
	while(n)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}

void preprocess()
{
	int i,j;
	for(i=2;i<400;i++)
		if(!hash[i])
			for(j=i+i;j<100000;j+=i)
				hash[j]=1;
	for(i=10000;i<=100000;i++)
		if(!hash[i]&&checksum(i)!= sum)
			hash[i]=1;
}

void dfs(int depth)
{
	if(depth==5)
	int gg=0;
	int row,col,i,j,data;
	if(depth==25)
	{
		data=0;
		for(i=0;i<5;i++)
			data+=grid[i][i]*pow[i];
		if(hash[data]) 
			return;
		memcpy(ans[top++].grid,grid,sizeof(grid));
		return;
	}

	row=seq[depth][0];
	col=seq[depth][1];
	for(i=0;i<=9;i++)
	{
		if((row==0||col==0)&&i==0)
			continue;
		grid[row][col]=i;
		if(sumrow[row]+i>sum)
			continue;
		if(sumcol[col]+i>sum)
			continue;
		if(sumrow[row]+i+(4-col)*9<sum)
			continue;
		if(sumcol[col]+i+(4-row)*9<sum)
			continue;
		if(row==4)
		{
			data=0;
			for(j=0;j<5;j++)
				data+=grid[j][col]*pow[j];
			if(hash[data])
				continue;
		}
		if(col==4)
		{
			data=0;
			for(j=0;j<5;j++)
				data+=grid[row][j]*pow[j];
			if(hash[data])
				continue;
		}
		if(row==2&&col==2)
		{
			data=0;
			for(j=0;j<5;j++)
				data+=grid[4-j][j]*pow[j];
			if(hash[data])
				continue;
		}
		sumrow[row]+=i;
		sumcol[col]+=i;
		dfs(depth+1);
		sumrow[row]-=i;
		sumcol[col]-=i;
	}
}

bool operator < (Answer a, Answer b)
{
	int i, j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(a.grid[i][j]!=b.grid[i][j])
				return a.grid[i][j]<b.grid[i][j];
	return 0;
}

int main()
{
	int i, x, y;
	scanf("%d%d",&sum,&first);
	preprocess();
	grid[0][0]=first;
	sumrow[0]=sumcol[0]=first;
	dfs(1);
	sort(ans,ans+top);
	for(i=0;i<top;i++)
	{
		for(x=0;x<5;x++)
		{
			for(y=0;y<5;y++)
				printf("%d",ans[i].grid[x][y]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}