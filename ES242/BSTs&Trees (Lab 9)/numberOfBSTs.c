#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        
        int dp[n+1];
        for (int i = 0; i < n+1; i++) 
            dp[i] = 0;
            
        
        dp[0]=1;
        dp[1]=1;
        
        for (int i = 2; i <=n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = dp[i]+ (dp[i-j]*dp[j-1]);
            }
        }
        printf("%d\n", dp[n]);
    }   
    return 0;
}
