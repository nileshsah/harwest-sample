#include <bits/stdc++.h>
typedef long long ll;
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


ll n, m;

inline ll id( ll i, ll j ) {
  return (i-1)*m + (j-1) + 1;
}

ll parent[1000005];
ll ans[1000005];
ll out[1000005];
ll in[1000005];
vector<ll> v[1000005];

ll find( ll x ) {
  if( parent[x] == x )
    return x;
  return parent[x] = find( parent[x] );
}

void join( ll x, ll y ) {
  ll p = find(x);
  ll q = find(y);
  
  if( p == q ) return;
  
  parent[p] = q;
}

int main() {
  BOOST;
  cin >> n >> m;
  
  ll a[n+1][m+1];
  memset( a, 0, sizeof a );
  
  FOR(i,1,n)
    FOR(j,1,m)  {
      cin >> a[i][j];
      parent[ id(i,j) ] = id(i,j);
    }
  
  FOR(i,1,n) {
    set< pair<ll,ll> > idx;
    pair<ll,ll> last = { -1, -1 };
    
    FOR(j,1,m) 
      idx.insert( { a[i][j], find( id(i,j) ) } );
    for( auto x : idx )
      if( last.F == x.F ) join( last.S, x.S ); 
      else last = x;
  }
  
  FOR(j,1,m) {
    set< pair<ll,ll> > idx;
    pair<ll,ll> last = { -1, -1 };
    
    FOR(i,1,n) 
      idx.insert( { a[i][j], find( id(i,j) ) } );
    for( auto x : idx )
      if( last.F == x.F ) join( last.S, x.S );
      else last = x;
  }
  
  FOR(i,1,n) {
    set< pair<ll,ll> > idx;
    pair<ll,ll> last = { -1, -1 };
    
    FOR(j,1,m) 
      idx.insert( { a[i][j], find( id(i,j) ) } );
    
    last = *idx.begin();
    idx.erase(idx.begin());
    for( auto x : idx ) {
      v[last.S].pb( x.S );
      out[last.S]++; in[x.S]++;
      last = x;
    }
  }
  
  FOR(j,1,m) {
    set< pair<ll,ll> > idx;
    pair<ll,ll> last = { -1, -1 };
    
    FOR(i,1,n) 
      idx.insert( { a[i][j], find( id(i,j) ) } );
    
    last = *idx.begin();
    idx.erase(idx.begin());
    for( auto x : idx ) {
      v[last.S].pb( x.S );
      out[last.S]++; in[x.S]++;
      last = x;
    }
  }
  
  queue< pair<ll,ll> > Q;
  
  FOR(i,1,n) 
    FOR(j,1,m) 
      if( !in[ find( id(i,j) ) ] && find( id(i,j) ) == id(i,j) )
        Q.push( { 1 , find( id(i,j) ) } );
  
  while(!Q.empty()) {
    ll d = Q.front().F;
    ll ptr = Q.front().S;
    Q.pop();
    
    ans[ptr] = d;

    for( ll x : v[ptr] ) {
      in[x]--;
      if( in[x] == 0 )
        Q.push( { d+1, x } );
    }
  }
  
  FOR(i,1,n) {
    FOR(j,1,m)
      cout << ans[ find( id(i,j) ) ] << ' ';
    cout << '\n';
  }
  
}
