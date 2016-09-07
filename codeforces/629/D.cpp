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

ll tree[100005];
map<ll,ll> h;
ll MaxVal = 100000;

double PI = 3.141592653589;


void update( ll idx, ll val ) {
  while( idx <= MaxVal ) {
    tree[idx] = max( tree[idx], val );
    idx += (idx&-idx);
  }
} 

ll read( ll idx ) {
  ll val = 0;
  while( idx > 0 ) {
    val = max( val, tree[idx] );
    idx -= (idx&-idx);
  }
  return val;
}

int main() {
  ll n; cin >> n;
  vector<ll> v, w;
  
  FOR(i,1,n) {
    ll r, h;
    cin >> r >> h;
    v.pb(r*r*h);
  }
  
  w = v;
  
  sort( all(w) );
  
  FOR(i,0,w.size()-1)
    h[ w[i] ] = i+1;
  
  ll ans = 0;
    
  FOR(i,0,v.size()-1) {
    ll q = read( h[ v[i] ] - 1 );
    q += v[i];
    update( h[ v[i] ], q );
    ans = max( ans, q );
  }
  
  printf("%0.6lf",PI*ans);
  
  
}
