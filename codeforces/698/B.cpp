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

ll parent[200005];
ll p[200005];
ll backup[200005];
bool explore[200005];
multiset<ll> v[200005];
set< pair<ll,ll> > cur;

ll find( ll x ) {
  if( p[x] == x ) return x;
  return p[x] = find( p[x] );
}

void join( ll x, ll y ) {
  ll a = find(x);
  ll b = find(y);
  
  if( a == b ) return;
  
  p[a] = b;
}

bool dfs( ll x, ll p = -1 ) {
    
  if( explore[x] ) {
    cur.insert( { min(x,p), max(x,p) } );
    return 1;
  }
  
  if( p != -1 )
    v[x].erase( v[x].find(p) );
  
  explore[x] = 1;
  for( ll q : v[x] ) {
    join( q, x );
    dfs( q, x );
  }
  
  if( p != -1 )
    v[x].insert(p);
  
  return 0;
}

int main() {
  ll n; cin >> n;
  
  FOR(i,1,n) {
    p[i] = i;
    cin >> parent[i];
    backup[i] = parent[i];
    if( parent[i] != i ) {
      v[ parent[i] ].insert(i);
      v[i].insert( parent[i] );
    }
  }
  
  vector<ll> head, loop;
  ll ans = 0;
  
  FOR(i,1,n)
    if( parent[i] == i ) {
      head.pb(i);
      dfs(i);
      cur.clear();
    }
  
  FOR(i,1,n)
    if( !explore[i] ) {
      dfs(i);
      
      vector<ll> c;
      for( auto x : cur ) c.pb( x.F );
      
      if( head.empty() ) {
        parent[ c[0] ] = c[0];
        head.pb( c[0] );
        c.erase(c.begin());
      }
      for( ll i = 0; i < (ll)c.size(); i++ ) {
        parent[ c[i] ] = head[i];
        join( c[i], head[i] );
      }
      cur.clear();
    }
  
  FOR(i,1,head.size()-1) 
    if( find( head[0] ) != find( head[i] ) ) {
      join( head[0], head[i] );
      parent[ head[i] ] = head[0];
    }
  
  FOR(i,1,n) if( backup[i] != parent[i] ) ans++;
  
  cout << ans << '\n';
  FOR(i,1,n) cout << parent[i] << ' ';
}
