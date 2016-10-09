#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.141592653589793
#define R 6378

struct city
{ 
	char name[30];
	double x,y,z; 
}c[1000];

int cities=0;

int read_city()
{
	double lo,la;
	scanf("%s",c[cities].name);
	if(strcmp(c[cities].name,"#")==0) 
		return 0;
	scanf("%lf %lf",&la,&lo);
	lo*=PI/180.0;
	la*=PI/180.0;
	c[cities].x=sin(lo)*cos(la);
	c[cities].y=cos(lo)*cos(la);
	c[cities].z=sin(la);
	cities++;
	return 1;
}

double distance(int i,int j)
{return acos(c[i].x*c[j].x+c[i].y*c[j].y+c[i].z*c[j].z)*R;}
 
int solve_case()
{
	char src[30],dst[30];
	int i,j;
	scanf("%s %s",src,dst);
	if(strcmp(src,"#")==0) 
		return 0;
	printf("%s - %s\n",src,dst);
	for (i=0;i<cities&&strcmp(c[i].name,src);i++);
	for (j=0;j<cities&&strcmp(c[j].name,dst);j++);
	if(i==cities||j==cities)
		printf("Unknown\n\n");
	else
		printf("%.0f km\n\n",distance(i,j));
	return 1;
}

int main()
{
  while(read_city());
  while(solve_case());
  return 0;
}