#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
/* Solution by divyanshu0x16*/
#define MAXN 100001
// No memory issues until 1e7

int spf[MAXN];

void seive(){
    spf[1]= 1;
    for (int i = 0; i < MAXN; i++) spf[i] = i;

    for (int i = 4; i < MAXN; i+=2) spf[i] = 2;

    for (int i = 3; i*i < MAXN; i++)
    {
        if ( spf[i] == i)
            for (int j = i*i; j < MAXN; j+= i)
                if ( spf[j] == j) spf[j] = i;
    }
}
 
 vector <int> getFactorization(int x){
     vector <int> ret;
     while (x != 1)
     {
         ret.push_back(spf[x]);
         x = x/spf[x];
     }
     return ret;
 }

 int main ( int argc, char const *argv[]){
     // precaluclating SPF
     seive();
     int x; cin >> x;
     cout << "Prime Factorization for " << x << " : ";

     vector <int> p = getFactorization(x);

     for (auto &&i : p) cout << i << " ";

     cout << endl;
     return 0;
 }