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
int a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t>0)
    {
        ll n;cin>>n;int high=-1;
        for(ll i=0;i<62;i++)
        {
            ll now=1ll<<i;
            if((n&now)!=0)
            {
                high=i;
            }
        }
        vector<int> v;v.resize(60);v[1]=1;
        for(int i=2;i<60;i++)
        {
            int now=(v[i-1]+v[i-2])%10;
            v[i]=now;
        }
        int zz=(1ll<<high)%60ll;
        cout<<v[zz-1]<<endl;
        t--;
    }
    return 0;
}