#include <iostream.h>
#include <stdio.h>
void main()
{
	char a[50],c[128];
	int i;
	for(i=0;i<128;i++)
		c[i]=-1;
	c['1']='`';c['2']='1';c['3']='2';c['4']='3';c['5']='4';c['6']='5';c['7']='6';c['8']='7';
	c['9']='8';c['0']='9';c['-']='0';c['=']='-';c['W']='Q';c['E']='W';c['R']='E';c['T']='R';
	c['Y']='T';c['U']='Y';c['I']='U';c['O']='I';c['P']='O';c['[']='P';c[']']='[';c['\\']=']';
	c['S']='A';c['D']='S';c['F']='D';c['G']='F';c['H']='G';c['J']='H';c['K']='J';c['L']='K';
	c[';']='L';c['\'']=';';c['X']='Z';c['C']='X';c['V']='C';c['B']='V';c['N']='B';c['M']='N';
	c[',']='M';c['.']=',';c['/']='.';
	while(gets(a))
	{
		i=0;
		while(a[i])
		{
			if(c[a[i]]<0)
				cout<<a[i];
			else
				cout<<c[a[i]];
			i++;
		}
		cout<<endl;
	}
}