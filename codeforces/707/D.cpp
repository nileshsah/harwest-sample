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

bool c[1005][1005];
vector<ll> v[100005];
pair<ll,ll> op[100005];
ll ans[100005];
ll go[100005];
ll n, m, q;

void rec( ll ptr, ll val ) {
   
  bool exec = 0;
  
  if( op[ptr].F < 0 && op[ptr].S < 0 ) {
    if( c[ abs(op[ptr].F) ][ abs(op[ptr].S) ] )
      c[ abs(op[ptr].F) ][ abs(op[ptr].S) ] = 0, exec = 1, val--;
  }
  else if( op[ptr].F > 0 && op[ptr].S > 0 ) {
    if( !c[ abs(op[ptr].F) ][ abs(op[ptr].S) ] )
      c[ abs(op[ptr].F) ][ abs(op[ptr].S) ] = 1, exec = 1, val++;
  }
  else if( op[ptr].F == 0 && op[ptr].S > 0 ) {
    ll r = op[ptr].S;
    exec = 1;
    FOR(i,1,m) {
      val += ( c[r][i] ) ? -1 : +1;
      c[r][i] = !c[r][i];
    }
  }
  
  ans[ptr] = val;
    
  for( ll x : v[ptr] )
    rec( x, val );
 
   
  if( exec && op[ptr].F < 0 && op[ptr].S < 0 ) 
    c[ abs(op[ptr].F) ][ abs(op[ptr].S) ] = 1;
  else if( exec && op[ptr].F > 0 && op[ptr].S > 0 )
    c[ abs(op[ptr].F) ][ abs(op[ptr].S) ] = 0;
  else if( exec && op[ptr].F == 0 && op[ptr].S > 0 ) {
    ll r = op[ptr].S;
    FOR(i,1,m) 
      c[r][i] = !c[r][i];
  }
    
}

int main() {
  BOOST;
  cin >> n >> m >> q;
  
  ll parent = 0;
  
  FOR(i,1,q) {
    ll w; cin >> w;
    if( w == 1 ) {
      ll x, y; cin >> x >> y;
      op[i] = { x, y };
    }
    else if( w == 2 ) {
      ll x, y; cin >> x >> y;
      op[i] = { -x, -y };
    }
    else if( w == 3 ) {
      ll r; cin >> r;
      op[i] = { 0, r };
    }
    
    if( w == 4 ) {
      ll idx; cin >> idx;
      op[i] = { 0, 0 };
      parent = go[idx];
      go[i] = go[idx];
    }
    else {
      go[i] = i;
      v[parent].pb(i);
      parent = i;
    }
  
  }
  
  rec(0,0);
  
  FOR(i,1,q) cout << ans[ go[i] ] << '\n';
  
}
