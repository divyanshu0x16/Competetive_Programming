#include <iostream>
#include <algorithm>

using namespace std;

const long long MAX = 1e9;
const long long N = 4001;

int main(){ 
        int T;
        cin >> T;
        for (int i=1; i<=T; i++){


            int n, k;
            cin >> n >> k;
            
            static int height[N];
            for(int i = 0; i < n; i++)
                cin>>height[i];
            
            // Sort the boxes according to height.
            sort(height, height + n);

            // First we will calcuate a quantity that will be useful later
            // See below for the main argument of the solution.
                        
            // T[i][h] := minimum height greater or equal than h that can be reached using only the last i elements, i.e,
            // the i largest elements.
            static int T[N][N];

            
            // Initialize the T array.
            for(int i = 0; i <= n ; i++)
                for(int j = 0; j <= k; j++)
                    T[i][j] = MAX;

            // Calculate T[i][h]'s below. 
            
            T[n][0] = 0;
            for(int i = n-1; i >= 0; i--){
                for(int j = k; j >= 0; j--){
                    if(j <= height[i]){
                        T[i][j] = height[i];
                        continue;
                    }
                    if(T[i+1][j-height[i]] == MAX)
                        T[i][j] = MAX;
                    else
                        //T[i+1][j] means we do not include ith box
                        //The other one means, we do include it and hence we need to find a previous one to it, 
                        //and count the height of ith box

                        T[i][j] = min(T[i+1][j-height[i]] + height[i], T[i+1][j]);

                        // Replace X and Y with two terms 
                        // based on whether the i-th box is being chosen or not.
                        // Remember to account for height[i] when you include the box!
                }
            }


            // Now, notice that TWO towers of height K can be built with b boxes [statement A] 
            // if and only if:
            // sum of heights of the b tallest boxes - T[b][K] >= K [statement B]

            // A => B
            
            // We are given that two towers of height K can be built with b boxes
            // Suppose X and Y are the sets of boxes witnessing this fact, and let
            // height of boxes in X = H1
            // height of boxes in Y = H2
            // Note that H1 >= K and H2 >= K
            
            // By definition, T[b][K] <= min(H1,H2)
            // and sum of heights of the b tallest boxes >= H1 + H2
            // so the desired claim follows.

            // B => A
            
            // B is true, so after taking away T[b][K] boxes 
            // the total height of the remaining boxes is also at least k.

            // So calcuate the sum of heights of b tallest boxes for all b 
            // in the array suffix: 
            
            static int suffix[N];
            suffix[n] = 0;
            for (int i = n-1; i >= 0; i--)
            {
                suffix[i] = suffix[i+1] + height[i];//Suffix array will store the sum of the height of the last i elements
            }
            int flag = 0;
            // Compute the entries of the suffix array here.
            for(int i = n-1; i >= 0; i--)
            // replace *** with the condition described in the comments.
                if( suffix [i] - T[i][k] >= k){
                    cout<< n-i <<"\n";
                    flag = 1;
                    break;
                }
            
            if(flag == 1) continue;
            cout << -1 <<"\n";  

         }
        return 0; 
}