#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; scanf("%d", &n);
    int ax, ay; scanf("%d %d", &ax, &ay);
    int bx, by; scanf("%d %d", &bx, &by);
    int cx, cy; scanf("%d %d", &cx, &cy);

    int flag = 0;
    
    if(by > cy) swap(&by, &cy);
    for (int i = by; i <= cy; i++)
        if(i == ay) flag = 1;
        
    if(bx > cx) swap(&bx, &cx);
    for (int i = bx; i <= cx; i++)
        if( i == ax ) flag = 1;
        

    if(flag) printf("NO\n");
    else printf("YES\n");
    
    return 0;
}
