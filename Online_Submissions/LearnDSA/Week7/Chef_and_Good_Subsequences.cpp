 
#include<bits/stdc++.h>
 
using namespace std;
 
typedef complex<double> base;
typedef long double ld;
typedef long long ll;
 
#define pb push_back
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>
#define vvi vector< vi >
const int maxn=(int)(2e5+5);
const ll mod=(ll)(1e9+7);
bool pr[maxn];
int a[maxn],cnt[maxn];
int dp[1100][1100];
 
int add(int a,int b)
{
    int ret=a+b;
    if(ret>=mod)
    {
        ret-=mod;
    }
    return ret;
}
 
int mul(int a,int b)
{
    ll ret=a*1ll*b;
    if(ret>=mod)
    {
        ret%=mod;
    }
    return (int)ret;
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       cnt[a[i]]++;
   }
   vector< int > v;v.pb(-1);
 
   for(int i=0;i<8000;i++)
   {
       if(cnt[i]>0)
       {
           v.pb(cnt[i]);
       }
   }
   assert(v.size()<=1010);
   k=min(k,(int)v.size());
 
   dp[0][0]=1;
   for(int i=1;i<v.size();i++)
   {
       dp[i][0]=1;
       for(int j=1;j<=k;j++)
       {
           dp[i][j]=add(dp[i-1][j],mul(dp[i-1][j-1],v[i]));
       }
   }
 
   int ret=0;
   for(int i=0;i<=k;i++)
   {
       ret=add(ret,dp[v.size()-1][i]);
   }
   cout<<ret<<endl;
    return 0;
}