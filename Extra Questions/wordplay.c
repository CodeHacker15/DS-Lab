#include <stdio.h>
#include <string.h>
void find_frequency(char s[], int count[]) 
{
   int c = 0;
   while (s[c] != '\0') 
    {
	   if (s[c] >= 'a' && s[c] <= 'z' )
       count[s[c]-'a']++;
	   c++;
	}
}
int main()
{
   char string[26];
   int count[26] = {0},i,a;
   scanf("%s",string);
   find_frequency(string, count);
   for(i=0;i<26;i++)
   {
		if(count[i]>1)
		{
			a = 0;
			break;
		}
   }
	if(a == 0)
		printf("no");
	else
		printf("yes");
	return 0;
}