#include <iostream>
using namespace std;

bool f;

void codon2(char *codon)
{
	switch(codon[0])
	{
		case 'T':
		switch(codon[1])
		{
			case 'T':
				switch(codon[2])
				{
					case 'T':cout<<"Phe";f=true;break;
					case 'C':cout<<"Phe";f=true;break;
					case 'A':cout<<"Leu";f=true;break;
					case 'G':cout<<"Leu";f=true;break;
				}
				break;
			case 'C':
				cout<<"Ser";f=true;break;
			case 'A':
				switch(codon[2])
				{
					case 'T':cout<<"Tyr";f=true;break;
					case 'C':cout<<"Tyr";f=true;break;
				}
				break;
			case 'G':
				switch(codon[2])
				{
					case 'T':cout<<"Cys";f=true;break;
					case 'C':cout<<"Cys";f=true;break;
					case 'G':cout<<"Trp";f=true;break;
				}
			}
			break;
		case 'C':
			switch(codon[1])
			{
				case 'T':cout<<"Leu";f=true;break;
				case 'C':cout<<"Pro";f=true;break;
				case 'A':
					switch (codon[2])
					{
						case 'T':cout<<"His";f=true;break;
						case 'C':cout<<"His";f=true;break;
						case 'A':cout<<"Gln";f=true;break;
						case 'G':cout<<"Gln";f=true;break;
					}
					break;
			case 'G':cout<<"Arg";f=true;break;
			}
			break;
			case 'A':
				switch(codon[1])
				{
					case 'T':
						switch(codon[2])
						{
							case 'G':cout<<"Met";f=true;break;
							default:cout<<"Ile";f=true;
						}
						break;
					case 'C':cout<<"Thr";f=true;break;
					case 'A':
						switch(codon[2])
						{
							case 'T':cout<<"Asn";f=true;break;
							case 'C':cout<<"Asn";f=true;break;
							case 'A':cout<<"Lys";f=true;break;
							case 'G':cout<<"Lys";f=true;break;
						}
						break;
					case 'G':
						switch(codon[2])
						{
							case 'T':cout<<"Ser";f=true;break;
							case 'C':cout<<"Ser";f=true;break;
							case 'A':cout<<"Arg";f=true;break;
							case 'G':cout<<"Arg";f=true;break;
						}
				}
				break;
			case 'G':
				switch(codon[1])
				{
					case 'T':cout<<"Val";f=true;break;
					case 'C':cout<<"Ala";f=true;break;
					case 'A':
						switch(codon[2])
						{
							case 'T':cout<<"Asp";f=true;break;
							case 'C':cout<<"Asp";f=true;break;
							case 'A':cout<<"Glu";f=true;break;
							case 'G':cout<<"Glu";f=true;break;
						}
						break;
					case 'G':cout<<"Gly";f=true;break;
				}
	}
}

void tran(char *dna,int codes)
{
	int i;
	for(i=0;i<codes;i++)
	{
		char codon[4];
		strncpy(codon,dna+3*i,3);
		codon[3]='\0';
		codon2(codon);
		if(i<codes-1)
			cout<<'-';
	};
	cout<<endl;
}

char *terminator(char *start)
{
	int i;
	for(i=6;i<strlen(start)-2;i+=3)
		if(start[i]=='T')
			switch (start[i+1])
			{
				case 'A':
					if(start[i+2]=='A'||start[i+2]=='G') 
						return start+i;
				case 'G':
					if(start[i+2] == 'A')
						return start+i;
			}
	return NULL;
}

int translate(char *dna)
{
	char *start=strstr(dna,"ATG");
	while(start!=NULL)
	{
		char *end=terminator(start);
		if(end)
		{
			tran(start+3,(end-start-3)/3);
			return 0;
		}
		else
			start=strstr(start+1,"ATG");
	}
	return 0;
}

void complement(char *dna)
{
	int i,l=strlen(dna);
	for(i=0;i<l;i++)
	{
		switch(dna[i])
		{
			case 'A':dna[i]='T';break;
			case 'C':dna[i]='G';break;
			case 'G':dna[i]='C';break;
			case 'T':dna[i]='A';break;
		}
	}
}

int main()
{
	char dna[256];
	while(cin>>dna&&*dna!='*')
	{
		f=false;
		translate(dna);
		if(!f)
			translate(strrev(dna));
		complement(dna);
		if(!f)
			translate(dna);
		if(!f)
			translate(strrev(dna));
		if(!f)
			cout<<"*** No translatable DNA found ***"<<endl;
	}
	return 0;
}
