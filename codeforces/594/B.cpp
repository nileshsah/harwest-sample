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

double EPS = 1e-7;

int main() {
  BOOST;
  
  ll n; double r, v;
  cin >> n >> r >> v;
  
  ll backup_n = n;
  
  while(n--) {
    double s, f;
    cin >> s >> f;
    
    double start = 0, end = 1e9;
    
    ll iter = (ll)(1e7)/backup_n;
    
    while( fabs(start-end) > EPS && iter ) {
      double mid = ( start + end )/2;
      double d = v*mid + fabs( 2 * r * sin( (v*mid)/(2*r) ) );
            
      if( d - (f-s) >= EPS ) end = mid;
      else start = mid;
      
      iter--;
    }
    
    printf("%0.7lf\n", end);
  }
}
