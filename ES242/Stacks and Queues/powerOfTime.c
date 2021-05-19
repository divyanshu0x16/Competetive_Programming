#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void move_last(int callingOrder[], int n){
    int temp;
    temp = callingOrder[0];
    for (int i = 1; i < n; i++) {
        callingOrder[i-1] = callingOrder[i];
    }
    callingOrder[n-1] = temp;
}

void remove_first(int a[], int n){
    int temp;
    temp = a[0];
    for (int i = 1; i < n; i++) {
        a[i-1] = a[i];
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    
    int callingOrder[100];
    int idealOrder[100];
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &callingOrder[i]);
    }for (int i = 0; i < n; i++) {
        scanf("%d", &idealOrder[i]);
    }
    int answer = 0;
    while (count != n) {
        while (callingOrder[0] != idealOrder[0]) {
            int length = n -count;
            move_last(callingOrder, length);
            answer++;
        }
        if (callingOrder[0] == idealOrder[0]) {
            int length = n-count;
            remove_first(callingOrder, length);
            remove_first(idealOrder, length);
            length = length-1;
            
            count++;
            answer++;
        }
    }
    printf("%d", answer);

    return 0;
}