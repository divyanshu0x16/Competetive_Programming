#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int bol(int k, int j, int i, char *string){
    for (int l = 0; l < i; l++) 
        if (string[k+l] != string[j+l])
            return 0;

    return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char string[1201];
    scanf("%s", string);
    
    int length = strlen(string);
    int count = (length*(length+1))/2;
    
    for (int i = 1; i < length; i++) 
        for (int j = 0; j < length-i+1; j++) 
            for (int k = j+1; k <= length-i; k++) 
            
                if (bol(k, j, i, string)) {
                    count--;
                    break;
                }
                
    printf("%d\n", count);
    return 0;
}