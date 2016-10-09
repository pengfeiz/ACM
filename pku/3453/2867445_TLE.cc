#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEAMS 100
#define HASH 377
#define MAX_NAME 110

static struct team
{
  char name[MAX_NAME];
  unsigned wins, loses, draws, points, spos, sneg;
} teams[MAX_TEAMS];

static unsigned gstat[MAX_NAME][MAX_NAME][2];
static unsigned round = 0;

static unsigned hash[HASH];
static unsigned n_teams,width,n;

static unsigned
hash_string (const char *ch)
{
  unsigned v = 0;

  for (; *ch; ch++)
    v = (67 * v + *ch) % HASH;

  return v;
}

static unsigned
find (const char *ch)
{
  unsigned h = hash_string (ch);

  while (strcmp (ch, teams[h].name))
    {
      h++;
      if (h == HASH)
	h = 0;
    }

  return h;
}

static void
insert (const char *ch, unsigned idx)
{
  unsigned h = hash_string (ch);

  while (hash[h] != ~0)
    {
      h++;
      if (h == HASH)
	h = 0;
    }

  hash[h] = idx;
}

static char *
shorten (char *ch)
{
  static char buf[5];
  strncpy (buf, ch, 3);
  buf[3] = 0;

  return buf;
}

static void
separator (void)
{
  int i;

  printf ("+");
  for (i = 0; i < width; i++)
    printf ("-");
  printf ("+");
  for (i = 0; i < n_teams; i++)
    printf ("---+");
  printf ("\n");
}

static int
get_score (unsigned rteam, unsigned cteam, int *a, int *b)
{
  *a = gstat[rteam][cteam][0];
  *b = gstat[rteam][cteam][1];

  if (*a <= round)
    return 0;

  *a -= round + 1;
  *b -= round + 1;

  return 1;
}

static void
print_table (void)
{
  int rteam, cteam, a, b;

  separator ();

  printf ("|%-*s|", width, "");
  for (cteam = 0; cteam < n_teams; cteam++)
    printf ("%-3s|", shorten (teams[cteam].name));
  printf ("\n");

  separator ();

  for (rteam = 0; rteam < n_teams; rteam++)
    {
      printf ("|%-*s|", width, teams[rteam].name);
      for (cteam = 0; cteam < n_teams; cteam++)
	{
	  if (rteam == cteam)
	    {
	      printf (" X |");
	      continue;
	    }

	  if(get_score(rteam,cteam, &a, &b))
	    printf ("%d:%d|",a,b);
	  else
	    printf ("   |");
	}
      printf ("\n");

      separator ();
    }
}

static int
compare_teams (const void *a, const void *b)
{
  int ia = *(int *) a;
  struct team *ta = teams + ia;
  int ib = *(int *) b;
  struct team *tb = teams + ib;
  int da, db;
  if (ta->points != tb->points)
    return tb->points - ta->points;

  da = ta->spos - ta->sneg;
  db = tb->spos - tb->sneg;

  if (da != db)
    return db - da;

  if (ta->spos != tb->spos)
    return tb->spos - ta->spos;

  if (ta->wins != tb->wins)
    return tb->wins - ta->wins;

  return ib - ia;
}

static void
fix_width (int *w, int val)
{
  int vw;

  if (val < 10)
    vw = 1;
  else if (val < 100)
    vw = 2;
  else if (val < 1000)
    vw = 3;
  else if (val < 10000)
    vw = 4;
  else
    exit (1);

  if (vw > *w)
    *w = vw;
}

static int
get_width3 (int val1, int val2, int val3)
{
  int i, vw, val;
	
  vw = 0;
  for(i=0;i<3;i++)
  {
    if(i==0) val = val1;
    else if(i==1) val = val2;
    else if(i==2) val = val3;
    if (val < 10)
      vw += 1;
    else if (val < 100)
      vw += 2;
    else if (val < 1000)
      vw += 3;
    else if (val < 10000)
      vw += 4;
    else
      exit (1);
  }
  return vw;
}

static void
fix_width3 (int *w, int val1, int val2, int val3)
{
  int vw;
	
  vw = get_width3(val1,val2,val3);
  if (vw > *w)
    *w = vw;
}




static void
print (void)
{
  int order[MAX_TEAMS];
  int i, j, a;
  int wrank = 1, wng = 1, wwon = 1, wdraw = 1, wlost = 1, ws = 1, wpts = 1;

  for (i = 0; i < n_teams; i++)
    order[i] = i;

  if(n_teams>1) qsort (order, n_teams, sizeof (int), compare_teams);

  for (i = 0; i < n_teams; i++)
    {
      fix_width (&wrank, i + 1);
      fix_width (&wng, teams[i].wins + teams[i].loses + teams[i].draws);
      fix_width (&wwon, teams[i].wins);
      fix_width (&wdraw, teams[i].draws);
      fix_width (&wlost, teams[i].loses);
      fix_width3 (&ws, teams[i].spos, 1, teams[i].sneg);
      fix_width (&wpts, teams[i].points);
    }

  for (i = 0; i < n_teams; i++)
    {
      a = order[i];
      printf ("%*d. ", wrank, i + 1);
      printf ("%-*s ", width, teams[a].name);
      printf ("%*d ", wng, teams[a].wins + teams[a].loses + teams[a].draws);
      printf ("%*d ", wwon, teams[a].wins);
      printf ("%*d ", wdraw, teams[a].draws);
      printf ("%*d ", wlost, teams[a].loses);
      for(j=0;j<ws-get_width3(teams[a].spos, 1, teams[a].sneg);j++) printf(" ");
      printf ("%d:", teams[a].spos);
      printf ("%d ", teams[a].sneg);
      printf ("%*d\n", wpts, teams[a].points);
    }
}

int main (void)
{    int k,m,p,aw;
    char t1[MAX_TEAMS],t2[MAX_TEAMS];
    int t1i,t2i,s1,s2;
    while(scanf("%d",&n),n)
    {
        n_teams=n;
        memset(hash,0,sizeof(hash));
        memset(teams,0,n*sizeof(struct team));
        width=0;
        for(k=0;k<n;k++)
        {
            scanf("%s",teams[k].name);
            insert(teams[k].name,k);
            aw=strlen(teams[k].name);
            if(aw>width)
                width=aw;
        }
        scanf("d",&m);
        for(k =0;k<m;k++)
	{
            scanf("%s - %s %d:%d",t1,t2,&s1,&s2);
            t1i=find(t1);
            t2i=find(t2);
            p=s1>s2?3:s1==s2?1:0;
            teams[t1i].wins+=p==3;
            teams[t1i].loses+=p==0;
            teams[t1i].draws+=p==1;
            teams[t1i].points+=p;
            teams[t1i].spos+=s1;
            teams[t1i].sneg+=s2;
            gstat[t1i][t2i][0]=round+1+s1;
            gstat[t1i][t2i][1]=round+1+s2;
            p=s1<s2?3:s1==s2?1:0;
            teams[t2i].wins+=p==3;
            teams[t2i].loses+=p==0;
            teams[t2i].draws+=p==1;
            teams[t2i].points+=p;
            teams[t2i].spos+=s2;
            teams[t2i].sneg+=s1;
        }
        printf("RESULTS:\n");
        print_table();
        printf("\nSTANDINGS\n----------\n");
        print();
        printf("\n");
        round+=20;
        }
    return 0;
}



