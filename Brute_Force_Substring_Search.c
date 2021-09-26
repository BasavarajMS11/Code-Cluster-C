#include <stdio.h>
#include <string.h>
void bruteforce(char* pat, char* txt)
{
        int i, j, k;
        int slen=strlen(txt);
        int plen=strlen(pat);
        for (int i=0;i<=slen-plen;i++)
        {
		int j;
		for (j=0;j<plen;j++)
			if (txt[i+j]!=pat[j])
				break;
        if (j==plen)
			printf("Pattern found at index %d \n", i);
	    }
  }
int main()
{   char txt[20];
    char pat[20];
    printf("Enter String\n");
	gets(txt);
	printf("Enter pattern to be searched\n");
	gets(pat);
	bruteforce(pat,txt);
	return 0;
}
