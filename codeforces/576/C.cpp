#include <bits/stdc++.h>
typedef int ll;
#define get(a) scanf("%lld", &a)
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main() {
  BOOST;
  ll n; cin >> n;
  
  vector< pair< pair<ll,ll>, ll > > points[1005];
  
  FOR(i,1,n) {
    ll x, y;
    cin >> x >> y;
    points[ x/1000 ].pb( { { y, x }, i } );
  }
  
  FOR(i,0,1000) {
    sort( all(points[i]) );
    if( i%2 )
      reverse( all(points[i]) );
  }
  
  FOR(i,0,1000)
    for( auto p : points[i] )
      cout << p.S << ' ';
}
