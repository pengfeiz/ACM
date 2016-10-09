#include <iostream>
using namespace std;

#define CHAINLENGTH 12

char chain[4][CHAINLENGTH+1];

int maxArea;
int area;

int TLPosition;

int TL, UL, LL, UR;

int LLPlacement;
int URPlacement;

int ULPosition, LLPosition, URPosition;

int main ( int argc, char ** argv )
{

 while(1)
 {
  cin >> chain[0];
  if ( chain[0][0] == 'Q' ) break;

  cin >> chain[1];
  cin >> chain[2];
  cin >> chain[3];

  maxArea = 0;

 for(TL=0;TL<4;TL++)
 {
  for (UL=0;UL<4;UL++)
  {
   if ( UL == TL ) continue;
   for (LL=0;LL<4;LL++)
   {
    if ( (LL==UL) || (LL==TL) ) continue;
    for(UR=0;UR<4;UR++)
    {
    if( (UR==LL) || (UR==UL) || (UR == TL) ) continue;
    for(TLPosition=1;TLPosition<(CHAINLENGTH-3);TLPosition++)
    {
     for(ULPosition=1;ULPosition<(CHAINLENGTH-3);ULPosition++)
     {
      if (chain[TL][TLPosition] != chain[UL][ULPosition]) continue;
      for(LLPlacement=TLPosition+2;
	  LLPlacement<(CHAINLENGTH-1);
	  LLPlacement++)
      {
       for(LLPosition=1;LLPosition<(CHAINLENGTH-3);LLPosition++)
       {
	if (chain[TL][LLPlacement] != chain[LL][LLPosition]) continue;
	for(URPlacement=ULPosition+2;
	    URPlacement<(CHAINLENGTH-1);
	    URPlacement++)
	{
	 for(URPosition=1;
	     URPosition<(CHAINLENGTH-3);
	     URPosition++)
	 {
          if(chain[UL][URPlacement] != chain[UR][URPosition])continue;

	  /* check lower right corner */
	
	  if((LLPosition+URPlacement-ULPosition)
	     >=
	     (CHAINLENGTH-1)
	     )continue; 

          if( (URPosition+LLPlacement-TLPosition)
	     >=
	     (CHAINLENGTH-1))continue;

	  if(chain[LL][LLPosition+URPlacement-ULPosition] 
	     !=
	     chain[UR][URPosition+LLPlacement-TLPosition]
	    )continue;


	  /* Found one! */

	  area = (LLPlacement-TLPosition-1)*(URPlacement-ULPosition-1);
	  if ( area > maxArea )
	    maxArea = area;
	 }
	}
       }
      }
     }
    }
    }
   }
  }
 }
  cout << maxArea << endl;
 }
 return 0;
}

