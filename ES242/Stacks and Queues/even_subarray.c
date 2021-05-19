#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    char stack[100001];
    char string[100001];
    
    
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%s", string );
        int stackIndex = -1;
        int stringIndex = 0;
        
        while (string[stringIndex] != '\0') {
            if (stackIndex != -1 && stack[stackIndex] == string[stringIndex]) {
                stackIndex--;
            }else {
                stackIndex++;
                stack[stackIndex] = string[stringIndex];
            }
            stringIndex++;
        }
        
        if (stackIndex == -1) {
            printf("KHALI\n");
        }else {
            stringIndex = 0;
            while ( stringIndex <= stackIndex) {
                printf("%c", stack[stringIndex]);
                stringIndex++;
            }
            printf("\n");
        }
    }
    return 0;
}