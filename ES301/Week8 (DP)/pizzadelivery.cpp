#include <iostream>
const long long INF = 1e9;
using namespace std;

int main(){
  int T;

  int i,j,k,max;
  int res;

  cin >> T;
  
  while(T--){
    int n;
    cin >> n; 
    
    int H[501], K[501];

    
    for(i = 0; i < n; i++){
        cin >> H[i]; 
    }    
    
    for(i = 0; i < n; i++){
        cin >> K[i]; 
    }

    max = 0;
    for(i = 0; i < n; i++){
        if(max < H[i]) 
            max = H[i];
    }

    int F[1001];

    // F[i] denotes minimum number of fuel station visits for obtaining exactly fuel i 
    // the maximum distance we need to travel is at most 2*max (back and forth)
    // initialize F:

    for(i = 0; i < 2*max + 1; i++){ 
        F[i] = INF;
    }
    
    F[0] = 0;

    for(i = 0; i < n; i++){
        for(j = K[i]; j < 2*max+1; j++){
            // the question here is: 
            // do you use the i-th fuel station or not? 
            // if yes, what value of F should you compare against? 
            F[j] = min(F[j], 1+F[j-K[i]]); //
        }
    }

    int answer = 0;
    //calculate the answer as the sum of the
    //appropriate H-values

    for(i = 0; i < n; i++){
        // add the cost of each trip to answer here.
        answer += F[2*H[i]]; //F stores the cost of each trip. Each trip will need 2*H[i]
    }
    
    cout << answer << endl; ; 
  
  }

  return 0;
}