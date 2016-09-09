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

char turn( pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c ) {
  pair<ll,ll> x = { b.F - a.F, b.S - a.S };
  pair<ll,ll> y = { c.F - b.F, c.S - b.S };
  
  if( x.F == 0 && y.S == 0 && x.S * y.F > 0 )
    return 'R';
  if( x.S == 0 && y.F == 0 && x.F * y.S < 0 )
    return 'R';
  return 'L';
}

int main() {
  ll n; cin >> n;
  vector< pair<ll,ll> > v;
  
  FOR(i,1,n+1) {
    ll x, y; 
    cin >> x >> y;
    
    v.pb( { x, y } );
  }
  
  ll ans = 0;
  
  FOR(i,1,n-1) {
    char c = turn( v[i-1], v[i], v[i+1] );
    //~ debug(c);
    if( c == 'L' )
      ans++;
  }
  
  cout << ans;
  
  
}
