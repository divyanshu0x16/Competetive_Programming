#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int get_length(char *s){
    int length = 0;
    
    while (s[length] != '\0') {
        length++;
    }
    
    return length;
}

int bah(char *s){
    int length = get_length(s);
    if (length%2) {
        return 0;
    }
    
    //We only to store the order of opening brackets
    char *stack = malloc(length/2);
    int stackIndex = 0;
    
    for (int i = 0; i < length; i++) {
        char curren = s[i];
        
        if (curren == '(' || curren == '{' || curren == '[') {
            if ( stackIndex == length/2) {
                return 0;
            }
            stack[stackIndex++] = curren;
        }else {
            if (stackIndex == 0) {
                return 0;  
            }
            // Idhar ek comment aaega. This is a call for help. I need sleep
            if ( (curren == ')' && stack[stackIndex-1] == '(') || 
                 (curren == ']' && stack[stackIndex-1] == '[') || 
                 (curren == '}' && stack[stackIndex-1] == '{') ) {
                     stackIndex--;
            }else {
                return 0;
            }
        }
    }
    free(stack);
    if (stackIndex == 0) {
        return 1;
    }else {
        return 0;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n;
    scanf("%d", &n);
    
    while (n--) {
        // set to the maximum possible length
        char string[1001];
        scanf("%s", string);
        
        if (bah(string)) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }
    return 0;
}