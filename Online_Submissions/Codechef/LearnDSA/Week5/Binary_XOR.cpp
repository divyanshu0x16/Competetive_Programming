#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
/* Solution by divyanshu0x16*/
//#define int           long long 
#define setbits(x)    __builtin_popcountll(x)
#define zerobits(x)   __builtin_ctzll(x)
//#define mod           1000000007 
#define modulo(a, b)  (a%b<0 ? a%b+b : a%b)
#define intpow(a,b)   (int)(pow(a,b) + 0.5)
#define gcd(a,b)      __gcd(a, b)
#define all(x)        (x).begin(), (x).end()
#define ps(x, y)      fixed<<setprecision(y)<<x
#define testcase(x)   int x; cin >> x; while(x--)
#define fastIO        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ordered_set   tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;


long long int power(long long int a,long long int b,long long int mod){
	if(b==0){
	    return 1;
	}
	long long int ans=power(a,b/2,mod);
	ans=(ans*ans)%mod;
	if(b%2==0){
	    return ans;
	}
	else{
	    return (ans*(a%mod))%mod;
	}
}
void boost(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void factorial(vector<long long int>&fact,long long int mod,long long int MAXX){
    long long int i;
    fact[0]=1;
    for(i=1;i<MAXX;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
}
long long int Inverse_Mod(long long int n,long long int mod){
    return power(n,mod-2,mod)%mod;
}
long long int nCr(long long int n,long long int r,long long int mod,vector<long long int>&fact){
    return (fact[n]*Inverse_Mod(fact[r],mod)%mod*Inverse_Mod(fact[n-r],mod)%mod)%mod; 
}

int32_t main(){
    boost();
    long long int i,n,t,mod=1000000007,MAXX=100005,a1,a0,b1,b0,minn,maxx,ans;
    vector<long long int>fact(MAXX);
    string a,b;
    factorial(fact,mod,MAXX);
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a;
        cin>>b;
        a1=0;
        a0=0;
        b0=0;
        b1=0;
        for(i=0;i<n;i++){
            if(a[i]=='1'){
                a1++;
            }
            else{
                a0++;
            }
            if(b[i]=='1'){
                b1++;
            }
            else{
                b0++;
            }
        }
        ans=0;
        minn=abs(a1-b1);
        maxx=min(a0,b1)+min(a1,b0);
        for(i=minn;i<=maxx;i+=2){
            ans=((ans%mod)+nCr(n,i,mod,fact)%mod)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}