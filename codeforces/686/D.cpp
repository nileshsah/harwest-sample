#include <bits/stdc++.h>
typedef int ll;
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

vector<ll> v[300005];
ll subtree[300005], size[300005];
ll centroid[300005], parent[300005];

bool is_centroid( ll root, ll node ) {
  if( size[root] - size[node] <= size[root]/2 && subtree[node] <= size[root]/2 )
    return 1;
  
  return 0;
}

ll dfs( ll x, ll p ) {
  parent[x] = p;
  size[x] = 1;
  
  for( ll q : v[x] ) {
    size[x] += dfs( q, x );    
    subtree[x] = max( subtree[x], size[q] );
  }
  
  return size[x];
}

void rec( ll x ) {
  if( v[x].empty() ) {
    centroid[x] = x;
    return;
  }
  
  ll ptr = 0;
  
  for( ll q : v[x] ) {
    rec( q );
    if( subtree[x] == size[q] )
      ptr = q;
  }
  
  ll c = centroid[ptr];
  while( !is_centroid( x, c ) )
    c = parent[c];

  centroid[x] = c;  
}

int main() {
  ll n, q; 
  cin >> n >> q;
  
  FOR(i,2,n) {
    ll p; cin >> p;
    v[p].pb(i);
  }
  
  dfs(1,-1);
  rec(1);
    
  while(q--) {
    ll x; cin >> x;
    cout << centroid[x] << '\n';
  } 
}
