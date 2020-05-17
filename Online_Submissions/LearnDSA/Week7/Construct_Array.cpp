//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define int ll
int c[2][2];
int mult(int a[2][2],int b[2][2]){
	int i,j,k;
	rep(i,2){
		rep(j,2){
			c[i][j]=0;
		}
	}
	rep(i,2){
		rep(j,2){
			rep(k,2){
				c[i][k]+=a[i][j]*b[j][k];
				c[i][k]%=mod;
			}
		}
	}
	rep(i,2){
		rep(j,2){
			a[i][j]=c[i][j];	
		}
	}
}
int a[2][2],res[2][2];
main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int val=m;
		val%=mod;
		int val2=val*val;
		val2%=mod;
		m--;
		m%=mod;
		n--;
		a[0][0]=m;
		a[0][1]=m;
		a[1][0]=1;
		a[1][1]=0;

		res[1][1]=1;
		res[0][0]=1;
		res[1][0]=0;
		res[0][1]=0;
		while(n){
			if(n%2){
				mult(res,a);
			}
			mult(a,a);
			n/=2;
		}
		//cout<<res[1][0]<< " "<<res[1][1]<<endl;
		val2*=res[1][0];
		val2%=mod;
		val2+=res[1][1]*val;
		val2%=mod;
		cout<<val2<<endl;
	}
	
	return 0;   
}