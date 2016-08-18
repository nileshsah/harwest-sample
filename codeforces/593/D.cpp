#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vector< pair<ll,ll> > adj[200005];
ll parent[200005];
ll P[200005];
ll depth[200005];
ll val[200005];
ll low[200005];
ll high[200005];


ll find( ll x ) {
  if( P[x] == x )
    return x;
  else
    return P[x] = find( P[x] );
}

void join( ll x, ll y ) {
  ll p = find(x);
  ll q = find(y);
  
  if( p == q ) return;
  
  P[p] = q;
  
  if( depth[ low[p] ] < depth[ low[q] ] )
    low[q] = low[p];
  
  if( depth[ high[p] ] > depth[ high[q] ] )
    high[q] = high[p];
  
}

ll PARENT( ll x ) {
  if( low[ find(x) ] == x )
    return parent[x];
  return low[ find(x) ];
}


void dfs( ll x, ll last, ll d ) {
 
  depth[x] = d;
  
  for( auto q : adj[x] ) {
    if( parent[q.F] != -1 )
      continue;

    val[q.F] = q.S;
    parent[q.F] = x;
    dfs( q.F, q.S, d+1 );
    
    if( q.S == 1 )
      join( x, q.F );
  }
  
}

int main() {
  BOOST;
  ll n, m;
  cin >> n >> m;
  
  memset( parent, -1, sizeof parent );
  
  vector< pair<ll,ll> > w;
  
  FOR(i,1,n-1) {
    ll u, v, x;
    cin >> u >> v >> x;
    
    adj[u].pb( { v, x } );
    adj[v].pb( { u, x } );
    
    w.pb( { u, v } );
  }
  
  FOR(i,1,n)
    P[i] = low[i] = high[i] = i;
  
  
  parent[1] = 0;
  dfs(1,-1,0);
  
  while(m--) {
    ll q; cin >> q;
    
    if( q == 1 ) {
      ll u, v, y;
      cin >> u >> v >> y;
      
      while( u != v && y > 0 ) {
        if( depth[u] >= depth[v] ) {
          y /= val[u];
          u = PARENT(u);
        }
        else {
          y /= val[v];
          v = PARENT(v);
        }
      }
      
      cout << y << '\n';
    }
    else if( q == 2 ) {
      ll id, c; cin >> id >> c;
      id--;
      
      ll ptr, other;
      
      if( depth[ w[id].F ] > depth[ w[id].S ] ) {
        ptr = w[id].F;
        other = w[id].S;
      }
      else {
        ptr = w[id].S;
        other = w[id].F;
      }
      
      val[ptr] = c;
      
      if( c == 1 ) join( ptr, other );
      
    }
    
  }
  
  
}
