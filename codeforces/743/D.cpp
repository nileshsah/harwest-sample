#include <bits/stdc++.h>
typedef long long ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl;
#define F first
#define S second
#define MEM(a,b) memset( a, b, sizeof a );
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll a[200005];
vector<ll> v[200005];

ll MaxVal;
ll INF = LLONG_MAX/100;

pair<ll,ll> dfs( ll x, ll p ) {
  ll val = a[x];
  vector<ll> idx;
  for( ll q : v[x] )
    if( q != p ) {
      auto d = dfs( q, x );
      idx.pb(d.S);
      val += d.F;
    }
  sort( idx.rbegin(), idx.rend() );
  if( idx.size() >= 2 )  
    MaxVal = max( MaxVal, idx[0] + idx[1] );
  if( idx.empty() )
    idx.pb(val);
  return { val, max(idx[0],val) } ;      
}

int main() {
  ll n; cin >> n;
  FOR(i,1,n) cin >> a[i];
  
  FOR(i,1,n-1) {
    ll x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  
  MaxVal = -INF;
  dfs(1,-1);
  
  if( MaxVal == -INF )
    cout << "Impossible";
  else
    cout << MaxVal;
}
