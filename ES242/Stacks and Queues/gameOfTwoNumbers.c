#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    
    long int stack[1000000];
    
    long int array[n];
    long int next_greater[n], next_smaller[n];
    for (int i = 0; i < n; i++) {
        scanf("%li", &array[i]);
    }
    
    memset(next_greater, -1, n*sizeof(next_greater[0]));
    memset(next_smaller, -1, n*sizeof(next_smaller[0]));
    
    int stackTop = -1;
    
    for (int i = 0; i < n; i++) {
        while (stackTop != -1) {
            if (array[i] > array[stack[stackTop]]) {
                next_greater[stack[stackTop]] = i;
                stackTop--;
            }else {
                break;
            }
        }
        ++stackTop;
        stack[stackTop] = i;
    }
    stackTop = -1;
    
    for (int i = 0; i < n; i++) {
        while (stackTop != -1) {
            if (array[i] < array[stack[stackTop]]) {
                next_smaller[stack[stackTop]] = i;
                stackTop--;
            }else {
                break;
            }
        }
        ++stackTop;
        stack[stackTop] = i;
    }
    
    for (int i = 0; i < n; i++) {
        if ( next_greater[i] != -1 && next_smaller[next_greater[i]] != -1) {
            printf("%li ", array[next_smaller[next_greater[i]]]);
        }else {
            printf("-1 ");
        }
    }
    printf("\n");
    
    return 0;
}