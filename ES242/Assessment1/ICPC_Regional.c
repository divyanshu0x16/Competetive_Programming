#include <stdio.h>
#include <stdlib.h>
 
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int n, i;
    scanf("%d", &n);
    
    int a[n];
    
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    
    //Sorting the array
    int size = sizeof(a)/sizeof(a[0]);
    qsort((void*)a, size, sizeof(a[0]), cmpfunc);
    
    int j = 0, ans = -1;
    //We check at each index the maximum length possible without exceeding 5 and store the current maximum
    for (int i = 0; i < n; i++)
    {
        // a1 a2 a3 a4 a4 a5. If j is at a4 then, a3-a1 <= 5. So a3-a2 <=5 Since a2 > a1. So we dont need to reset j.
        while ( a[j]-a[i] <= 5 ){
            if ( j >= n ) break;
            j++;
        }
        if (ans < (j-i))
            ans = j-i;
    }

    printf("%d\n", ans);
        
    
    return 0;
}