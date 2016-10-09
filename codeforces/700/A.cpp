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

int main() {
  ll n, l, k;
  double v1, v2;
  
  cin >> n >> l >> v1 >> v2 >> k;
  
  ll r = ceil(1.0*n/k), iter = 200;
  
  double start = 0.0, end = 1e9;
  while( fabs(start-end) > 1e-6 ) {
    double t = ( start + end )/2;
    double minDist = l - ( t*v1*v2 - v1*l )/( v2 - v1 );
    
    double elapsed = 0, cur = 0;
    
    bool exceed = 0;
    
    FOR(i,1,r) {
      elapsed += ( cur - elapsed * v1 )/( v1 + v2 );
      cur = v1 * elapsed + minDist;
      
      double dist = elapsed * v1;
      if( l - dist < minDist )
        exceed = 1;
      elapsed += minDist/v2;
    }
    
    if(!exceed) end = t;
    else start = t;
    
    iter--;
    if(iter<0) break;
  }
  
  printf("%0.7lf", start);
}
