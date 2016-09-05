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

ll foo( vector< pair<ll,ll> > v ) {
  if( v[0].S == v[1].S && v[0].S == v[2].S )
    return 1;
  if( v[0].F == v[1].F && v[0].F == v[2].F )
    return 1;
  if( v[0].F == v[1].F && ( v[2].S <= min(v[0].S,v[1].S) || v[2].S >= max(v[0].S,v[1].S) ) )
    return 2;
  if( v[0].S == v[1].S && ( v[2].F <= min(v[0].F,v[1].F) || v[2].F >= max(v[0].F,v[1].F) ) )
    return 2;
  return 3;
}

int main() {
  ll x, y;
  vector< pair<ll,ll> > v;
  
  while( cin >> x >> y )
    v.pb( { x, y } );
  
  ll ans = 3;
  
  sort( all(v) );
  
  do{
    ans = min( foo(v), ans );
  }while( next_permutation( all(v) ) );
  
  cout << ans;
}
