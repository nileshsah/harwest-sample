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

string s, t;

ll dp[1001][1001][11][2];

ll rec( ll i, ll j, ll left, bool last = 0 ) {
  if( j >= (int)t.size() || i >= (int)s.size() )
    return 0;
  if( dp[i][j][left][last] != -1 )
    return dp[i][j][left][last];
    
  ll ans = 0;
  if( s[i] == t[j] && ( left > 0 || last ) ) {
    if( last )
      ans = max( ans, 1 + rec( i+1, j+1, left, 1 ) );
    if( left > 0 )
      ans = max( ans, 1 + rec( i+1, j+1, left-1, 1 ) );
  }
  
  ans = max( ans, rec( i+1, j, left, 0 ) );
  ans = max( ans, rec( i, j+1, left, 0 ) );
  
  return dp[i][j][left][last] = ans;
}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  
  cin >> s >> t;
  
  memset( dp, -1, sizeof dp );
  
  cout << rec( 0, 0, k );
}
