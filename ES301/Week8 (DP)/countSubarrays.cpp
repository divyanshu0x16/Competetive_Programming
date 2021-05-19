#include <iostream>
using namespace std;

#define MAXN 100000


int main()
{
    int T;
    cin >> T;
    
    while(T--){
        int n;
        cin >> n;
        
        long int answer = 0, count = 0;
        int arr[n];
        long int ans[n];
        // Let ans[i] denote the number of non-decreasing arrays
        // in the arr[0...i].

        for(int i=0; i<n; i++){
            cin >> arr[i];
            ans[i] = 1;
            // Initializing ans[i] to 1
            // since the subarray with the singleton element ans[i] is non-decreasing
            // so ans[i] is at least 1 always.
        }

        for(int i=1; i<n; i++){
            if(arr[i-1] <= arr[i] ) ans[i] = ans[i-1]+1 ;//If the i-1 th element is less than or equal to ith element then we add one
        }
        
        // Calcuate the final answer as the sum of all numbers
        // in the ans array.
      
        for(int i=0; i<n; i++){
            answer += ans[i];
        }
      
      
        cout << answer << endl;
    }
    return 0;
}