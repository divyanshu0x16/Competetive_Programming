#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct suffix{
    int index;
    char *suff;
}suffix;

int cmp(const void *v1, const void *v2){
    const suffix *ia = (suffix *)v1;
    const suffix *ib = (suffix *)v2;
    return strcmp(ia->suff, ib->suff); 

}

void suffixArray(char *txt, int suffixArr[]){
    
    int n = strlen(txt);
    struct suffix suffixes[n];
    
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }
    
    qsort(suffixes, n, sizeof(struct suffix),cmp);
    
    for (int i = 0; i < n; i++) {
        suffixArr[i] = suffixes[i].index;
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char string[551];
    scanf("%s", string);
    
    int suffixArr[strlen(string)];
    
    suffixArray(string, suffixArr);
    
    for (int i = 0; i < strlen(string); i++) {
        printf("%d ", suffixArr[i]);
    }

    printf("\n");
    
    return 0;
}
