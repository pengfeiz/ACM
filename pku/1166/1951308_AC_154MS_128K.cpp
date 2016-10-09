# include <iostream>
using namespace std;
int move[9][9]={
	{1,1,0,1,1,0,0,0,0},
	{1,1,1,0,0,0,0,0,0},
	{0,1,1,0,1,1,0,0,0},
	{1,0,0,1,0,0,1,0,0},
	{0,1,0,1,1,1,0,1,0},
	{0,0,1,0,0,1,0,0,1},
	{0,0,0,1,1,0,1,1,0},
	{0,0,0,0,0,0,1,1,1},
	{0,0,0,0,1,1,0,1,1} 
};
int clock[9];
int temp[9];
int m[9];
int Move();
void Output();
int main()
{	
	int i;
	for(i=0;i<9;i++)
		cin>>clock[i];
	for (m[0]=0;m[0]<=3;m[0]++)
	for (m[1]=0;m[1]<=3;m[1]++)
	for (m[2]=0;m[2]<=3;m[2]++)
	for (m[3]=0;m[3]<=3;m[3]++)
	for (m[4]=0;m[4]<=3;m[4]++)
	for (m[5]=0;m[5]<=3;m[5]++)
	for (m[6]=0;m[6]<=3;m[6]++)
	for (m[7]=0;m[7]<=3;m[7]++)
	for (m[8]=0;m[8]<=3;m[8]++)
	{
		if(Move()==1)
		{
			Output();
			break;
		}		
	}
	return 0;
}

int Move()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		temp[i]=clock[i];
		for(j=0;j<9;j++)
			temp[i]+=m[j]*move[j][i];
		if(temp[i]%4!=0)
			return 0;
	}
	return 1;
}

void Output(){
	int i,j;
	for (i=0;i<9;i++){
		if (m[i]>0)
			for (j=0;j<m[i];j++)
				cout<<i+1<<' ';
	}
	cout<<endl;
}
