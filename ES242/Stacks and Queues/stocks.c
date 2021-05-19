#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void calAnswer(int stocks[], int n, int answer[]){
    answer[0] = 1;
    
    for (int i = 1; i < n; i++) {
        int counter = 1;
        while ((i-counter) >= 0 && stocks[i] >= stocks[i-counter]) {
            counter += answer[i-counter];
        }
        answer[i] = counter;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    
    int stocks[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &stocks[i]);
        
    int answer[n];
    
    calAnswer(stocks, n, answer);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}