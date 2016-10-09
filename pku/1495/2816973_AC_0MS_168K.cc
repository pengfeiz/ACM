#include <cstdio>

int onSegments[] = {
 0x7E, 0x30, 0x6D, 0x79, 0x33,
 0x5B, 0x5F, 0x70, 0x7F, 0x7B
};

void printLED ( int sample )
{
 int mask = 0x40;
 int i;
 printf("LED sample: ");
 for(i=0;i<7;i++, mask >>= 1)
  printf("%c", ( sample & mask )? 'Y':'N');
 printf("\n");
}

int kase = 0;
int BOSegments;
int numberOfSamples;
int numberOfBurnedOutSegments;
int sequenceMatch;

int sampleArray[10];

int main ()
{
 int i, j;
 int start, length;
 char buf[10];

 while(1)
 {
  scanf("%d", &numberOfSamples);
  if ( numberOfSamples == 0 ) break;

  kase++;

  for(i=0;i<numberOfSamples;i++)
  {
   scanf ( "%s", buf );
   sampleArray[i] = 0;
   for(j=0;j<7;j++)
   {
    if ( buf[j] == 'Y' )
    {
      sampleArray[i] |= 0x40 >> j;
    }
   }
  }

 for(start=9; start>=numberOfSamples-1;start--)
 {
  BOSegments = 0;
  sequenceMatch = 1;
  for(i=0;i<numberOfSamples;i++)
  {
   if(((~sampleArray[i] |(onSegments[start-i] & ~BOSegments))&0x7F)==0x7F)
    BOSegments = BOSegments|(onSegments[start-i]&~sampleArray[i]&~BOSegments);
   else
   {
    sequenceMatch = 0;
    break;
   }
  }

  if ( sequenceMatch ) break;
 }
  if ( sequenceMatch )
   printf("MATCH\n");
  else
  {
   printf("MISMATCH\n");
  }
}
 return 0;
}
