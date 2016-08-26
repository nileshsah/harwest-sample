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

ll inf = LLONG_MAX/10000;

ll R[2005], L[2005];
ll n, h; double p;
vector<ll> v;

double dp[2005][2005][2][2];
bool explore[2005][2005][2][2];


double rec( ll x, ll y, bool lastx, bool lasty ) {
  if( x > y )
    return 0.0;
  if( explore[x][y][lastx][lasty] )
    return dp[x][y][lastx][lasty];
  
  // lastx -> 0 x-1 has fallen left
  // lastx -> 1 x-1 has fallen right 
  
  ll last_left = ( lastx == 0 ) ? v[x-1] : v[x-1]+h;
  ll last_right = ( lasty == 0 ) ? v[y+1]-h : v[y+1];
  
  double ans = 0.0;
  
  // x falls left
  ans += p*( rec( x+1, y, 0, lasty ) + v[x] - max( v[x]-h, last_left) );
  // x falls right
  if( R[x] < y ) ans += (1-p)*( rec( R[x]+1, y, 1, lasty ) + v[ R[x] ] + h - v[x] );
  else ans += (1-p)*( rec( R[x]+1, y, 1, lasty ) + min( v[y]+h, last_right ) - v[x] );
  
  // y falls right
  ans += (1-p)*( rec( x, y-1, lastx, 1 ) + min( v[y]+h, last_right ) - v[y] );
  // y falls left
  if( L[y] > x ) ans += p*( rec( x, L[y]-1, lastx, 0 ) + v[y] + h - v[ L[y] ] );
  else ans += p*( rec( x, L[y]-1, lastx, 0 ) + v[y] - max( last_left, v[x]-h ) );
  
  
  explore[x][y][lastx][lasty] = 1;
  return dp[x][y][lastx][lasty] = ans*0.5;

}

int main() {
  BOOST;
  cin >> n >> h >> p;
  
  v.resize(n+2);
  v[0] = -inf; v[n+1] = inf;
  
  FOR(i,1,n) cin >> v[i];
    
  sort( all(v) );
  
  FOR(i,1,n) {
    
    ll ptr = i+1;
    while( ptr <= n && v[ptr]-v[ptr-1] < h ) ptr++;
    R[i] = ptr-1;
    
    ptr = i-1;
    while( ptr > 0 && v[ptr+1]-v[ptr] < h ) ptr--;
    L[i] = ptr+1;
  }
  
  
  printf("%0.7lf", rec(1,n,0,1) );
}
