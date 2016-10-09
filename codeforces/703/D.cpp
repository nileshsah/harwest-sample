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

ll tree[1000005];
ll MaxVal = 1000000;

void update( ll idx, ll val ) {
  while( idx <= MaxVal ) {
    tree[idx] ^= val;
    idx += (idx&-idx);
  }
}

ll read( ll idx ) {
  ll val = 0;
  while( idx > 0 ) {
    val ^= tree[idx];
    idx -= (idx&-idx);
  }
  return val;
}

int main() {
  BOOST;
  ll n; cin >> n;
  
  ll a[n+1], x[n+1];
  x[0] = 0;
  
  map<ll,ll> last;
  
  FOR(i,1,n) {
    cin >> a[i];
    x[i] = (x[i-1]^a[i]);
  }
  
  ll q; cin >> q;
  vector< pair< pair<ll,ll>, ll > > Q;
  ll ans[q+1];
  
  FOR(i,1,q) {
    ll l, r; cin >> l >> r;
    Q.pb( { { r, l }, i } );
  }
  sort( all(Q) );
  
  ll ptr = 0;
  
  FOR(i,1,n) {
    if( last.find(a[i]) != last.end() )
      update( last[ a[i] ], a[i] );
    update( i, a[i] );
    last[ a[i] ] = i;
    
    while( ptr < q && Q[ptr].F.F == i ) {
      ans[ Q[ptr].S ] = ( read( Q[ptr].F.F )^read( Q[ptr].F.S-1 ) );
      ans[ Q[ptr].S ] ^= ( x[ Q[ptr].F.F ]^x[ Q[ptr].F.S-1 ] );
      ptr++;
    }
    
  }
  
  FOR(i,1,q) cout << ans[i] << '\n';
  
}
