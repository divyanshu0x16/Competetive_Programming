#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testcase;
    scanf("%d", &testcase);
    while (testcase--){
        char s[1000001];
        scanf("%s", s);
        printf("%s", s);
    }
    return 0;
}