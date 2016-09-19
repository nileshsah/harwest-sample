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

ll tree[4][301][301] = {0};

ll INF = INT_MAX;
ll MaxVal = 300;

const int TL = 0, TR = 1, BR = 2, BL = 3;

void update( ll x, ll y, ll q ) {
  ll val;
// For pts in bottom right
  val = q - x - y;
  for( ll i = x; i <= MaxVal; i += (i&-i) )
    for( ll j = y; j <= MaxVal; j += (j&-j) )
      tree[BR][i][j] = min( tree[BR][i][j], val );
        
// For pts in bottom left
  val = q - x + y;
  for( ll i = x; i <= MaxVal; i += (i&-i) )
    for( ll j = y; j > 0; j -= (j&-j) )
      tree[BL][i][j] = min( tree[BL][i][j], val );

// For pts in top right
  val = q + x - y;
  for( ll i = x; i > 0; i -= (i&-i) )
    for( ll j = y; j <= MaxVal; j += (j&-j) )
      tree[TR][i][j] = min( tree[TR][i][j], val );

// For pts in top left
  val = q + x + y;
  for( ll i = x; i > 0; i -= (i&-i) )
    for( ll j = y; j > 0; j -= (j&-j) )
      tree[TL][i][j] = min( tree[TL][i][j], val );
}

ll read( ll x, ll y ) {
  ll val = INF;
// For pts in bottom right
  for( ll i = x; i <= MaxVal; i += (i&-i) )
    for( ll j = y; j <= MaxVal; j += (j&-j) )
      val = min( tree[TL][i][j] - x - y, val );
  
// For pts in bottom left
  for( ll i = x; i <= MaxVal; i += (i&-i) )
    for( ll j = y; j > 0; j -= (j&-j) )
      val = min( tree[TR][i][j] - x + y, val );

// For pts in top right
  for( ll i = x; i > 0; i -= (i&-i) )
    for( ll j = y; j <= MaxVal; j += (j&-j) )
      val = min( tree[BL][i][j] + x - y, val );

// For pts in top left
  for( ll i = x; i > 0; i -= (i&-i) )
    for( ll j = y; j > 0; j -= (j&-j) )
      val = min( tree[BR][i][j] + x + y, val );
  
  return val;
}


void reset( ll x, ll y ) {
// For pts in bottom right
  for( ll i = x; i <= MaxVal; i += (i&-i) )
    for( ll j = y; j <= MaxVal; j += (j&-j) )
      tree[BR][i][j] = INF;
        
// For pts in bottom left
  for( ll i = x; i <= MaxVal; i += (i&-i) )
    for( ll j = y; j > 0; j -= (j&-j) )
      tree[BL][i][j] = INF;

// For pts in top right
  for( ll i = x; i > 0; i -= (i&-i) )
    for( ll j = y; j <= MaxVal; j += (j&-j) )
      tree[TR][i][j] = INF;

// For pts in top left
  for( ll i = x; i > 0; i -= (i&-i) )
    for( ll j = y; j > 0; j -= (j&-j) )
      tree[TL][i][j] = INF;
}


int main() {
  ll n, m, P;
  cin >> n >> m >> P;
  
  MaxVal = max(n,m);
  
  ll arr[n+1][m+1];
  ll dp[n+1][m+1];
  
  vector< pair<ll,ll> > v[P+1];
  
  FOR(k,0,3) FOR(i,0,MaxVal) FOR(j,0,MaxVal ) tree[k][i][j] = INF;
  
  FOR(i,1,n) 
    FOR(j,1,m) {
      cin >> arr[i][j];
      if( arr[i][j] == 1 )
        dp[i][j] = i + j - 2;
      v[ arr[i][j] ].pb( {i,j} );
    }
  
  ll ans = INF;
  
  FOR(k,2,P) {
    for( auto p : v[k-1] ) 
      update( p.F, p.S, dp[p.F][p.S] );
    for( auto p : v[k] ) 
      dp[p.F][p.S] = read( p.F, p.S );
    for( auto p : v[k-1] )
      reset( p.F, p.S );
  }
  
  for( auto p : v[P] )
    ans = min( ans, dp[p.F][p.S] );
    
  cout << ans;
  
}
