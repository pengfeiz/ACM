#include <iostream> 
using namespace std; 

/*****交换2个数*****/ 
void swap_ab(int& a, int& b) 
{ 
int tmp = a; 
a = b; 
b = tmp; 
} 

int main() 
{ 

int x1; 
cin >> x1; 

 
int x2; 
cin >> x2; 


int y1; 
cin >>y1; 


int y2; 
cin >>y2; 


int m; 
cin >>m; 

//保证y1-y2>=0 
if ( y1 < y2 ) 
{ 
swap_ab(y1,y2); 
swap_ab(x1,x2); 
} 

int k = 0; 
while ( ((x1-x2)+(y1-y2)*k)%m != 0 ) 
{ 
++k; 
if( k>=0x7fffffffffffffff ) 
{ 
break; 
} 
} 
cout <<k <<endl; 
return 0; 
} 
endl; 
return 0; 
} 