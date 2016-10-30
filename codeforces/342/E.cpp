#include <bits/stdc++.h>
typedef int ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl;
#define F first
#define S second
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll tree[100005], n, m;
const ll INF = INT_MAX/10;
const ll MAXN = 100005, MaxVal = 100000;
vector<ll> v[MAXN], Q[MAXN], updated, explored;
ll depth[MAXN], sz[MAXN], ans[MAXN], first[MAXN];
bool used[MAXN] = {0};

void update( ll idx, ll val ) {
  updated.pb(idx);
  while( idx <= MaxVal ) {
    tree[idx] = min( tree[idx], val );
    idx += (idx&-idx);
  } 
}

ll read( ll x ) {
  ll val = INF;
  while(x>0) {
    val = min( val, tree[x] );
    x -= (x&-x);
  }
  return val;
}

void reset() {
  for( ll idx : updated ) {
    while( idx <= MaxVal ) {
      tree[idx] = INF;
      idx += (idx&-idx);
    }
  }
  updated.clear();
}

void dfsTree( ll x, ll p = -1 ) {
  explored.pb(x);
  sz[x] = 1;
  for( ll q : v[x] )
    if( q != p && !used[q] ) {
      dfsTree( q, x );
      sz[x] += sz[q];
    }
}

ll centroid( ll x, ll p, ll _size ) {
  for( ll q : v[x] )
    if( q != p && !used[q] && sz[q] > _size/2 )
      return centroid( q, x, _size );
  return x;
}

void dfsColor( ll x, ll p = -1, ll d = 0 ) {
  depth[x] = d;
  if( first[x] != INF )
    update( first[x], d );
  for( ll q : v[x] )
    if( q != p && !used[q] )
      dfsColor( q, x, d+1 );
}

void solve( ll r ) {
  reset();
  explored.clear();
  dfsTree(r);
  ll c = centroid(r,-1,sz[r]);
  used[c] = 1;
  dfsColor(c);
  
  
  for( ll x : explored )
    for( ll t : Q[x] )
      ans[t] = min( ans[t], depth[x] + read(t) );
      
  for( ll x : v[c] )
    if( !used[x] )
      solve(x);
}

int main() {
  BOOST;
  cin >> n >> m;
  
  FOR(i,1,n-1) {
    ll x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  
  FOR(i,1,MAXN-1) tree[i] = first[i] = ans[i] = INF;
  first[1] = 1;
  
  FOR(i,1,m) {
    ll t, v;
    cin >> t >> v;
    
    if( t == 1 )
      first[v] = min( first[v], i );
    else if( t == 2 )
      Q[v].pb(i);
  }
  
  solve(1);
  
  FOR(i,1,m)
    if( ans[i] != INF )
      cout << ans[i] << '\n';
      
}
