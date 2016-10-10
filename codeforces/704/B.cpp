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

ll dp[2][5001][2][2];
ll x[5005], a[5005], b[5005], c[5005], d[5005];

ll INF = LLONG_MAX/5500LL;

int main() {
  BOOST;
  ll n, start, end;
  cin >> n >> start >> end;
  
  FOR(i,0,1) FOR(j,0,n) FOR(k,0,1) FOR(l,0,1) dp[i][j][k][l] = INF;
  dp[0][0][0][0] = 0;
  
  FOR(i,1,n) cin >> x[i];
  FOR(i,1,n) cin >> a[i];
  FOR(i,1,n) cin >> b[i];
  FOR(i,1,n) cin >> c[i];
  FOR(i,1,n) cin >> d[i];
  
  ll ans = INF;
  
  FOR(ptr,1,n) {
    bool cur = (ptr&1);
    bool last = !cur;
    
    FOR(j,0,n) FOR(k,0,1) FOR(l,0,1) dp[cur][j][k][l] = INF;
    
    FOR(io,0,n) 
      FOR(in,0,1) 
        FOR(out,0,1)
          if( dp[last][io][in][out] != INF ) {
            
            ll val = dp[last][io][in][out], now = 0;
            
            if( ptr != start && ptr != end ) {
              
              // in from left, out to left
              now = ( x[ptr] + a[ptr] ) + ( x[ptr] + c[ptr] );
              if( io + in + out >= 2 )
                dp[cur][io-1][in][out] = min( dp[cur][io-1][in][out], now + val );
              if( ptr == n and !io and in and out )
                ans = min( ans, now + val );
              
              // in from left, out to right 
              now = ( x[ptr] + a[ptr] ) + ( -x[ptr] + d[ptr] );
              if( io or out )
                dp[cur][io][in][out] = min( dp[cur][io][in][out], now + val );
              
              // in from right, out to left
              now = ( -x[ptr] + b[ptr] ) + ( x[ptr] + c[ptr] );
              if( io or in )
                dp[cur][io][in][out] = min( dp[cur][io][in][out], now + val );
              
              // in from right, out to right
              now = ( -x[ptr] + b[ptr] ) + ( -x[ptr] + d[ptr] );
              dp[cur][io+1][in][out] = min( dp[cur][io+1][in][out], now + val );
            
            }
            else if( ptr == start && !out ) {
              
              // From start to left
              now = x[ptr] + c[ptr];
              if( io )
                dp[cur][io-1][in][1] = min( dp[cur][io-1][in][1], now + val );
              if( ptr == n and !io and in )
                ans = min( ans, now + val );
                
              // From start to right
              now = -x[ptr] + d[ptr];
              dp[cur][io][in][1] = min( dp[cur][io][in][1], now + val );

            } 
            else if( ptr == end && !in ) {
              
              // From left to end
              now = x[ptr] + a[ptr];
              if( io )
                dp[cur][io-1][1][out] = min( dp[cur][io-1][1][out], now + val );
              if( ptr == n and !io and out )
                ans = min( ans, now + val );
                
              // From right to end
              now = -x[ptr] + b[ptr];
              dp[cur][io][1][out] = min( dp[cur][io][1][out], now + val );
              
            }           
          } 
          
  }
  
  cout << ans;
  
}
