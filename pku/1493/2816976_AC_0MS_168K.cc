#include <cstdio>

#define MAXROWS 30
#define MAXCOLUMNS 25

int kase = 0;
char newLine;

int N;
int readChar;
char image[MAXROWS][MAXCOLUMNS];
int blanksPerRow[MAXROWS];
int minBlanksPerRow;
int totalBlanks;

int main ()
{
 int row, column;

 while(scanf("%d", &N),N)
 {
  totalBlanks = 0;kase++;
  minBlanksPerRow = MAXCOLUMNS;
  for(row=0;row<N;row++)
  {
   blanksPerRow[row] = 0;
   readChar = getchar();
   for(column=0;column<MAXCOLUMNS;column++)
   {
    readChar = getchar();
    image[row][column] = (char) readChar;
    if ( image[row][column] == ' ' ) blanksPerRow[row]++;
   }
  totalBlanks += blanksPerRow[row];
  if ( blanksPerRow[row] < minBlanksPerRow )
    minBlanksPerRow = blanksPerRow[row];
  }
  printf("%d\n", totalBlanks - N * minBlanksPerRow );
 }
 return 0;
}