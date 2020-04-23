#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
#define pb push_back
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
 
inline ll mul(ll x, ll y, ll m)
{
	ll z = 1LL * x * y;
	if (z >= m)
	    z %= m;
	return z;
}
 
ll n, blockSize, a[100050], b[1000050], m[1000050], p[100050][17], level[100050], in[100050], c,
	out[100050], ans[100050], rev[200050], val[200050], cur[200050], inv[2000050], moLeft, moRight;
vector<ll> adj[100050];
vector<pair<ll, ll>> f[1000050];
vector<pair<pair<ll, ll>, pair<pair<ll, ll>, ll>>> query;
 
void sieve()
{
	f(1, 1000050) b[i] = i;
	f(2, 1000050) b[i] = 2, i++;
	for (ll i = 3; i * i < 1000050; i += 2)
	{
	    if (b[i] == i)
	    {
	        for (ll j = i * i; j < 1000050; j += i)
	            if (b[j] == j)
	                b[j] = i;
	    }
	}
}
 
ll powmod(ll x, ll y)
{
	ll r = 1;
	while (y)
	{
	    if (y & 1)
	        r = mul(r, x, mod);
	    y >>= 1;
	    x = mul(x, x, mod);
	}
	return r;
}
 
ll hilbertorder(ll x, ll y)
{
	ll maxn = 1LL << 20, logn = 20;
	long long d = 0;
	for (ll s = 1 << (logn - 1); s; s >>= 1)
	{
	    bool rx = x & s, ry = y & s;
	    d = d << 2 | rx * 3 ^ static_cast<ll>(ry);
	    if (!ry)
	    {
	        if (rx)
	        {
	            x = maxn - x;
	            y = maxn - y;
	        }
	        swap(x, y);
	    }
	}
	return d;
}
 
bool compare(pair<pair<ll, ll>, pair<pair<ll, ll>, ll>> a, pair<pair<ll, ll>, pair<pair<ll, ll>, ll>> b)
{
	return a.second.second < b.second.second;
}
 
void dfs(ll x, ll pr)
{
	in[x] = c++;
	p[x][0] = pr;
	f(0, adj[x].size()) if (adj[x][i] != pr) level[adj[x][i]] = level[x] + 1, dfs(adj[x][i], x);
	out[x] = c++;
}
 
void pre()
{
	fi(1, 17)
	    f(1, n + 1) if (p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];
}
 
ll lca(ll u, ll v)
{
	if (level[u] > level[v])
	    swap(u, v);
	ll d = level[v] - level[u];
	while (d)
	{
	    ll raise = log2(d);
	    v = p[v][raise];
	    d -= (1LL << raise);
	}
	if (u == v)
	    return u;
	fr(16, 0) if (p[u][j] != p[v][j]) u = p[u][j], v = p[v][j];
	return p[u][0];
}
 
vector<pair<ll, ll>> factors(ll x)
{
	vector<pair<ll, ll>> fac;
	while (x != 1)
	{
	    ll y = b[x], ct = 0;
	    while (x % y == 0)
	        x /= y, ct++;
	    fac.pb({y, ct});
	}
	return fac;
}
 
void remove(ll in);
 
void add(ll in)
{
	if (cur[rev[in]] & 1)
	{
	    remove(in);
	    return;
	}
	cur[rev[in]] ^= 1;
	ll v = val[in];
	if (v == 1)
	    return;
	if (f[v].size() == 0)
	    f[v] = factors(v);
	f(0, f[v].size())
	{
	    c = mul(c, inv[m[f[v][i].first] + 1], mod),
	    c = mul(c, f[v][i].second + m[f[v][i].first] + 1, mod),
	    m[f[v][i].first] += f[v][i].second;
	}
}
 
void remove(ll in)
{
	if (!(cur[rev[in]] & 1))
	{
	    add(in);
	    return;
	}
	cur[rev[in]] ^= 1;
	ll v = val[in];
	if (v == 1)
	    return;
	if (f[v].size() == 0)
	    f[v] = factors(v);
	f(0, f[v].size())
	{
	    c = mul(c, inv[m[f[v][i].first] + 1], mod),
	    c = mul(c, m[f[v][i].first] - f[v][i].second + 1, mod),
	    m[f[v][i].first] -= f[v][i].second;
	}
}
 
void moQuery(ll l, ll r)
{
	while (moLeft < l)
	    remove(moLeft++);
	while (moLeft > l)
	    add(--moLeft);
	while (moRight < r)
	    add(++moRight);
	while (moRight > r)
	    remove(moRight--);
}
 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	sieve();
	f(0, 2000050) inv[i] = powmod(i, mod - 2);
	ll t, x, y;
	cin >> t;
	while (t--)
	{
	    memset(m, 0, sizeof(m));
	    memset(p, -1, sizeof(p));
	    memset(cur, 0, sizeof(cur));
	    query.clear();
	    cin >> n;
	    blockSize = sqrt(n);
	    f(0, n + 2) adj[i].clear();
	    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
	    f(1, n + 1) cin >> a[i];
	    c = 1;
	    dfs(1, -1);
	    f(1, n + 1) val[in[i]] = val[out[i]] = a[i], rev[in[i]] = rev[out[i]] = i;
	    pre();
	    ll q;
	    cin >> q;
	    f(1, q + 1)
	    {
	        cin >> x >> y;
	        ll k = lca(x, y);
	        if (k != x && k != y)
	        {
	            if (out[x] < in[y])
	                query.pb({{out[x], in[y]}, {{in[k], i}, hilbertorder(out[x], in[y])}});
	            else
	                query.pb({{out[y], in[x]}, {{in[k], i}, hilbertorder(out[y], in[x])}});
	        }
	        else
	        {
	            if (k == x)
	                query.pb({{in[x], in[y]}, {{-1, i}, hilbertorder(in[x], in[y])}});
	            else
	                query.pb({{in[y], in[x]}, {{-1, i}, hilbertorder(in[y], in[x])}});
	        }
	    }
	    sort(query.begin(), query.end(), compare);
	    c = 1;
	    moLeft = 1, moRight = 0;
	    f(0, query.size())
	    {
	        ll l = query[i].first.first,
	            r = query[i].first.second,
	            lca = query[i].second.first.first,
	            in = query[i].second.first.second;
	        moQuery(l, r);
	        ll currentAns = c;
	        if (lca != -1)
	            add(lca), currentAns = c, remove(lca);
	        ans[in] = currentAns;
	    }
	    f(1, q + 1) cout << ans[i] << "\n";
	}
 
	return 0;
}