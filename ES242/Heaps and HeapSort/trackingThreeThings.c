#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}

int main(){
    int n, i;
    scanf("%d", &n);

    int array[n];

    for(i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    qsort(array, 3, sizeof(int), cmpfunc);
    int product3 = array[2], product2 = array[1], product1 = array[0];

    int ans = product1*product2*product3;

    printf("-1\n");
    printf("-1\n");
    printf("%d\n", ans);

    for (int i = 3; i < n; i++) {
        if ( array[i] > product3) {
            product1 = product2;
            product2 = product3;
            product3 = array[i];
        }else if ( array[i] > product2 ) {
            product1 = product2;
            product2 = array[i];
        }else if ( array[i] > product1 ) {
            product1 = array[i];
        }
        ans = product1*product2*product3;
        printf("%d\n", ans);
    }
    return 0;
}
    