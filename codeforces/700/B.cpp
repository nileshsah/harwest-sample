#include <bits/stdc++.h>
typedef long long ll;
#define repVector(v)  for( auto it = v.begin(); it != v.last(); it++ )
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl;
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
#define OUTFILE freopen("output.out","w",stdout)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

bool is[200005];

vector<ll> v[200005];
ll k, dist[200005], unv[200005], sz[200005];

pair<ll,ll> dfs( ll x, ll p = -1, ll lvl = 0 ) {
  dist[x] = lvl;
  ll val = 1, sp = is[x];
  for( ll q : v[x] )
    if( q != p ) {
      auto it = dfs( q, x, lvl+1 );
      val += it.F; sp += it.S;
    }
  unv[x] = sp; sz[x] += val;
  return { val, sp };
}

ll dNode, dChild = INT_MAX;

void rec( ll x, ll p ) {
  if( unv[x] >= k ) {
    if( dChild > sz[x] )
      dChild = sz[x], dNode = x;
  }
  else if( unv[x] < k )
    return;
  
  for( ll q : v[x] )
    if( q != p )
      rec( q, x );
}


int main() {
  BOOST;
  ll n;
  cin >> n >> k;
  
  FOR(i,1,2*k) {
    ll x; cin >> x;
    is[x] = 1;
  }
  
  FOR(i,1,n-1) {
    ll x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
    
  FOR(i,1,n)
    if( v[i].size() == 1 ) {
      dfs(i);   
      rec( i, -1 );
      dfs( dNode, -1 );
  
      break;
    }
  
  long long ans = 0;
  FOR(i,1,n)
    if( is[i] )
      ans += dist[i];
    
  cout << ans;    
}
