#include <bits/stdc++.h>
//Solution form editorial
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define cd complex<double> 
#define vv vector
 
using namespace std;
 
const int INF = 1e9;
const int MAXN = 1e5+5;
const ll MOD = 1e9 + 7;
 
ll fxp(ll a, ll b){
	if(b == 0)return 1;
	if(b%2 == 0){
		ll c = fxp(a,b/2);
		return (c*c)%MOD;
	}
	return (a*fxp(a,b-1))%MOD;
}
 
//#define data pair<pair<ll,ll>,pair<int,int> >
struct data{
	int t;
	int x;
	int a;
	int id;
};
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		ll h;
		cin >> h >> n;
		data arr[n];
		FOR(i,n)cin >> arr[i].t >> arr[i].x >> arr[i].a,arr[i].id = i;
		sort(arr,arr+n,[&](data d1,data d2){
			return d1.x < d2.x;
		});
		int ans[n];
		FOR(i,n)ans[i] = 0;
		FOR(i,n){
			ll num_up,num_down,denom_up,denom_down;
			bool gotType0 = 0;
			bool gotType1 = 0;
			FORE(j,i+1,n-1){
				ll h = arr[j].a - arr[i].a;
				ll w = arr[j].x - arr[i].x;
						
				bool posFromBelow = 0;
				if(!gotType0)posFromBelow = 1;
				else{
					if(h*denom_down > w*num_down){ // means seeable
						if(arr[j].t == 0)denom_down = w;
						if(arr[j].t == 0)num_down = h;
						posFromBelow = 1;
					} 
				}
				bool posFromAbove = 0;
				if(!gotType1)posFromAbove = 1;
				else{
					if(h*denom_up < w*num_up){ // means seeable
						if(arr[j].t == 1)denom_up = w;
						if(arr[j].t == 1)num_up = h;
						posFromAbove = 1;
					}	
				}
 
				if(posFromBelow and posFromAbove)ans[arr[i].id]++,ans[arr[j].id]++;
				if(!gotType1 and arr[j].t == 1){
					gotType1 = 1;
					denom_up = w;
					num_up = h;
				}
				if(!gotType0 and arr[j].t == 0){
					denom_down = w;
					num_down = h;
					gotType0 = 1;
				}
 
			}
		}
		FOR(i,n)cout << ans[i] << " ";cout << endl; 
	}
 
	return 0;
}