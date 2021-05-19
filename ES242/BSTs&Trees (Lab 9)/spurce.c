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
    int degree[n];
    
    memset(array, 0, n*sizeof(array[0]));
    memset(degree, 0, n*sizeof(degree[0]));
    
    for (int i = 1; i < n; i++){
        scanf("%d", &array[i]);
        array[i]--;
        //Deg stores the number of children at each index
        degree[array[i]]++;
    }
    
    
    int sl[n];
    memset(sl, 0, n*sizeof(sl[0]));
    
    //sl stores the number of leaves
    for (int i=0; i < n; i++) {
        if (degree[i] == 0) {
            sl[array[i]]++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (degree[i] > 0 && sl[i] < 3) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    
    return 0;
}