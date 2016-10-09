#include <stdio.h>
#include <string.h>
int Digit[26];
char a[16],b[40000][16];
int n,l,len,max;
const int Value[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
bool Becan(char s[]);
int main()
{
	int i,j;
	scanf("%s",a);
	n=strlen(a);
	for( i=0; i<26; i++)
		Digit[i] = 0;
	for (i=0; i<n; i++)
		Digit[a[i]-'a']++;
	char str[16];
	max = len = 0;
	int val;
	bool ok = false;
	while (scanf("%s",str) && strcmp(str,"."))
	{
		if (ok) continue;
		l = strlen(str);
		if (l > n) continue;
		if (Becan(str))
		{
			val = 0;
			for (i=0; i<l; i++)
			{
				val += Value[str[i]-'a'];
				if (n == 6 && l == 3 || n == 7 && (l == 3 || l == 4))
					strcpy(b[len++],str);
			}
			if (max < val) max = val;
			if (l == n) 
			{
				ok = true; continue;
			}
		}			
	}
	if (ok) goto end;
	int k,h;
	char temp[16];
	
	for (i=0; i<len-1; i++)
	{
		
		strcpy(temp,b[i]);
		
		for (j=i+1; j<len; j++)
		{	
			strcat(temp,b[j]);
			h = strlen(b[i]) + strlen(b[j]);
			if (Becan(temp))
			{
				val = 0;
				for (k=0; k<h; k++)
					val += Value[temp[k]-'a'];
				if (val > max) max = val;
				if (h == n) goto end;
			}
		}
	}
end: printf("%d\n",max);
	return 0;
}
bool Becan(char s[])
{
	int i,k,D[26];
	for (i=0; i<26; i++)
		D[i] = Digit[i];
	k = strlen(s);
	for (i=0; i<k; i++)
	{
		D[s[i]-'a']--;
		if (D[s[i]-'a'] < 0)  return false;
	}
	return true;
}