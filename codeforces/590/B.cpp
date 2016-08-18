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

double EPS = 1e-12;

int main() {
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  
  ll vmax, t;
  cin >> vmax >> t;
  
  double vx, vy, wx, wy;
  cin >> vx >> vy >> wx >> wy;
  
  double start = 0.0, end = 1e12;
  
  ll iter = 0;
  
  while( fabs( start - end ) > EPS && iter < (ll)(1e7) ) {
    double mid = ( start + end )/2;
    
    double dist = 0.0;
    
    if( mid <= t ) {
      double xn = x1 + vx*mid;
      double yn = y1 + vy*mid;
      
      dist = sqrt( pow( x2 - xn, 2 ) + pow( y2 - yn, 2 ) );
    }
    else {
      double xn = x1 + vx*t + wx*(mid-t);
      double yn = y1 + vy*t + wy*(mid-t);
      
      dist = sqrt( pow( x2 - xn, 2 ) + pow( y2 - yn, 2 ) );
    }
    
    double tk = dist/vmax;
    
    if( tk - mid <= EPS )
      end = mid;
    else
      start = mid;
    
    iter++;    
  }
  
  
  printf("%0.7lf",start);
  
  
}
