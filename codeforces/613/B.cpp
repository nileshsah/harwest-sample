#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) ;//cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main() {
  ll n, A, cf, cm, m;
  cin >> n >> A >> cf >> cm >> m;
  
  vector< pair<ll,ll> > v(n);
  
  FOR(i,0,n-1) {
    cin >> v[i].F;
    v[i].S = i;
  }
  
  sort( v.rbegin(), v.rend() );
  
  vector< pair<ll,ll> > sum(n+1,{0,0});
  
  ROF(i,n-1,0) {
    sum[i].S = sum[i+1].S + v[i].F;
    sum[i].F = v[i].F;
  }
  
  ll ans = 0, left = m, fill = -1, minVal = -1;
  
  FOR(i,0,n) {
    
    ll start = 0, end = A;
    while( start <= end ) {
      ll mid = ( start + end )/2;
      
      ll x = i, y = n-1;
      while( x <= y ) {
        ll m = ( x + y )/2;
        if( v[m].F > mid-1 )
          x = m+1;
        else
          y = m-1;
      }
      
      debug(x); debug(mid);
      
      if( (n-x)*mid - sum[x].S > left )
        end = mid-1;
      else
        start = mid+1;
    }
    
    debug(i); debug(left); debug(end);
    
    if( ans < i*cf + end*cm ) {
      fill = i-1; minVal = end;
      ans = i*cf + end*cm;
    }
    
    if( i < n ) left -= A-v[i].F;
    if( left < 0 ) break;
  }
  
  vector<ll> f(n);
  
  FOR(i,0,n-1) {
    if( fill >= i )
      f[ v[i].S ] = A;
    else
      f[ v[i].S ] = max( minVal, v[i].F );
  }
  
  
  cout << ans << '\n';
  for( ll x : f  ) cout << x << ' ';
}
