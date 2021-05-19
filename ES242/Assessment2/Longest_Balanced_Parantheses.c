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
        
        int length = 0, currSum = 0;
        
        for (int i = 0; s[i] != '\0'; i++)
            length++;
        
        int ans = 0;
        for (int i = 0; i < length; i++) {
            //We take '<' as +1 and '>' as -1
            if ( s[i] == '<') {
                currSum++;
            }else {
                currSum--;
            }
            // If it becomes less than zero, then our input was something like '>><<<<<', hence our answer will be 0.
            if ( currSum < 0) {
                break;
            }
            // The index it becomes zero, everything is balanced, we keep counting for cases like '<<>><><>>>><<<'
            if (currSum == 0) {
                ans = i+1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}