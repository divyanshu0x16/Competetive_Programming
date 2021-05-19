#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);
        
    printf("%d ", array[0]);
    for(int i = 2; i < n; i = i*2)
        printf("%d ", array[i-1]);
        
    printf("\n");
    
    return 0;
}