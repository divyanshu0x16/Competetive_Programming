#include<stdio.h>
#include<stdlib.h>


int arraySorted(int arr[], int n){
    for (int i = 0; i < n-1; i++)
        if (arr[i] > arr[i+1])
            return 0;

    return 1;
}
 
int main()
{
    int t,n,m,i;
 
    scanf("%d",&t);
 
    while(t--)
    {
        scanf("%d %d",&n,&m);
 
        int a[n], p[n];
 
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for (int i = 0; i < n; i++)
            p[i] = 0;
        
        // Jo jo positionpe swap allowed hai wahan pe p[i] = 1
        int index;
        for (int i = 0; i < m; i++) {
            scanf("%d", &index);
            p[index-1] = 1;
        }

        //Keep Trying possible swaps
        int totalIterations = n, temp;
        while (totalIterations--)
        {
            if (arraySorted(a, n) == 1){
                printf("YES\n");
                break;
            }
            
            for (int i = 0; i < n-1; i++)
            {
                if (p[i] && a[i] > a[i+1])
                {
                    temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                }       
            }
        }

        if (arraySorted(a, n) == 0)
            printf("NO\n");
 
    }

    
    return 0;
}
 