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

int main() {
  ll n; cin >> n;
  
  set< pair< pair<ll,ll>, ll > > idx;
  idx.insert( { { 0, INT_MAX }, -1 } );
  
  while(n--) {
    ll x; cin >> x;
    auto it = idx.lower_bound( { {x,-1}, -1 } );
    it--;
    
    ll start = it->F.F, end = it->F.S;
    ll parent = it->S;
    
    idx.erase(it);
    idx.insert( { { start, x }, x } );
    idx.insert( { { x, end }, x } );
    
    if( parent != -1 ) cout << parent << ' ';
  }
  
}
