#include<bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
#define pb push_back
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;	cin>>t;
	while(t--){
		string s;	cin>>s;
		ll open=0,ans=0;
		ll n=s.size();
		bool flag=true;
		for(ll i=0;i<n;i++){
			if(s[i]=='<')
				open++;
			else {
				if(open==0)
					break;
				else{
					open--;
					if(open==0)
						ans=i+1;
				}
			}
		}
		cout<<ans<<"\n";
	}	
	return 0;
}