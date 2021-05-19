#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int pstrcmp( const void* a, const void* b )
{
  return strcmp( *(const char**)a, *(const char**)b );
}

int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

void printSubstr(char *words, int index){
    for (int i = 0; i <= index; i++)
        printf("%c", words[i]);
    printf("\n");
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, index; scanf("%d", &n);
    char str[1000][1000], temp[1000];

    for(int i=0; i<n; i++)
        scanf("%s", str[i]);

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(strcmp(str[i],str[j])>0){
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }


    //qsort(strings, n, sizeof(strings[0][1]), pstrcmp);
    
    char prefix[1000];

    int length = min(strlen(str[0]), strlen(str[n-1]));

    for (int i = 0; i < length; i++)
        if (str[0][i] != str[n-1][i])
        {
            index = i;
            break;
        }

    if (index == 0)
        printf("-1\n");
    else
        printSubstr(str[0], index-1);

    return 0;
}