#include <stdio.h>
#include <ctype.h>

char C[12][12];

void set(int i, int j) { if (C[i][j] == ' ') C[i][j] = '*'; }

void rook(int i, int j) {
  int i1, j1;
  for (i1=i+1; i1<10 && (C[i1][j] == ' ' || C[i1][j] == '*'); i1++) set (i1,j);
  for (i1=i-1; i1>1 && (C[i1][j] == ' ' || C[i1][j] == '*'); i1--) set (i1, j);
  for (j1=j+1; j1<10 && (C[i][j1] == ' ' || C[i][j1] == '*'); j1++) set (i,j1);
  for (j1=j-1; j1>1 && (C[i][j1] == ' ' || C[i][j1] == '*'); j1--) set (i,j1);
}

void bishop(int i, int j) {
  int i1, j1;
  for (i1=i+1, j1=j+1; 
       i1 < 10 && j1 < 10 && (C[i1][j1] == ' ' || C[i1][j1] == '*');
       i1++, j1++)    set (i1, j1);
  for (i1=i-1, j1=j-1; 
       i1 > 1 && j1 > 1 && (C[i1][j1] == ' ' || C[i1][j1] == '*');
       i1--, j1--)    set (i1, j1);
  for (i1=i-1, j1=j+1; 
       i1 > 1 && j1 < 10 && (C[i1][j1] == ' ' || C[i1][j1] == '*');
       i1--, j1++)    set (i1, j1);
  for (i1=i+1, j1=j-1; 
       i1 < 10 && j1 > 1 && (C[i1][j1] == ' ' || C[i1][j1] == '*');
       i1++, j1--)    set (i1, j1);
}

int main () {
  char buf[100];
  char ch;
  int i, j, s, res;

  while (fgets(buf, 100, stdin)) {

    for (i=0; i < 12; i++)
      for (j=0; j < 12; j++)
	if (i < 2 || i > 9 || j < 2 || j > 9) C[i][j]='.'; else C[i][j]=' ';

    s=0; i=9; j=2;
    while ((ch=buf[s++]) != '\n') {
      if (ch == '/') { i--; j=2; continue; }
      if (isdigit(ch)) {
	int cc=ch - '0';
	while (cc--) j++;
	continue;
      }
      C[i][j++]=ch;
    }
    for (i=2; i < 10; i++)
      for (j=2; j < 10; j++) 
	switch (ch=C[i][j]) {
	case 'P': set (i+1, j-1); set (i+1, j+1); break;
	case 'p': set (i-1, j-1); set (i-1, j+1); break;
	case 'R':
	case 'r': rook(i, j); break;
	case 'N':
	case 'n':
	  set (i+1, j-2); set (i+2,j-1); set (i+2,j+1); set(i+1, j+2);
	  set (i-1, j-2); set (i-2,j-1); set (i-2,j+1); set(i-1, j+2); break;
	case 'B':
	case 'b': bishop(i, j); break;
	case 'Q':
	case 'q': rook(i, j); bishop(i, j); break;
	case 'K':
	case 'k':
	  set(i+1, j-1); set(i+1, j); set(i+1, j+1); set(i, j-1), set(i, j+1);
	  set(i-1, j-1); set(i-1, j); set(i-1, j+1); break;
	case '*': 
	case ' ': break;
	default: printf("Wrong character %c\n", ch);
	  exit(0);
	}

    res=0;
    for (i=2; i < 10; i++)
      for (j=2; j < 10; j++)
	if (C[i][j] == ' ') res++;
    printf("%d\n", res);
  }
  return 1;
}
