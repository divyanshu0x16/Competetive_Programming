#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define FI(i,a,n) for(int i=a; i<=n; i++)
#define RFI(i,n,a) for(int i=n; i>=a; i--)
#define FLL(i,a,n) for(ll i=a; i<=n; i++)
#define RFLL(i,n,a) for(ll i=n; i>=a; i--)
#define vi vector<int>
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pi pair<int, int>
#define GCD(a,b) __gcd(a,b)
#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define debug(x) cout << x << endl
#define MOD 1000000007
#define INF LLONG_MAX
#define PI 3.14159265359
using namespace std;
 
// Watch its editorial. Highly Informative.

int main()
{
	fastio
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int a[n], b[n], c[n], d[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    int val=0;
    for(int i=0; i<n; i++) val ^= (a[i]^b[i]);
    for(int i=0; i<n; i++) c[i] = a[i]^val, d[i]=c[i]; /* XOR is commutative and assotiave. Har element ka XOR lenge Ai^Bi ke sath ussey x
    x ki value aaegi. x ka XOR Ai se kar, to Ci aaega. Dono array ko sort karke compare karna, permutation check karne ke liye.*/
    bool flag=true;
    sort(b,b+n);
    sort(c,c+n);
    for(int i=0; i<n; i++)
    {
      if(b[i]!=c[i])
      {
        flag=false;
        break;
      }
    }
    if(flag)
    {
      for(int i=0; i<n; i++) cout << d[i] << " " ;
    }
    else cout << -1;
    cout << "\n";
  }

	
	return 0;
}


