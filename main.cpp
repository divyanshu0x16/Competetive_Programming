#include <stdio.h>
#include<math.h>
// include other appropriate headers here, as per your requirement

int main(void) {
    int n;
    scanf("%d",&n);

    // Write your logic here. You can define helper functions if you want.

    long long size=pow(2,n)-1;
    long long int arr[size];
    long long int p=1;
    arr[0]=1;
    int i=1;
    for(int t=1; t<n; t++){
        arr[p]=1;
        for(long long int k=p+1; k<(2*p)+1; k++){
            if(arr[(2*p)-k]==0){
                arr[k]=1;
            }else{
                arr[k]=0;
            }
        }
        p=(2*p)+1;
    } 
    for(long long int l=0; l< size; l++){
        printf("%lld ", arr[l]);
    }
        

        

    
    
    return 0;
}