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

int main() {
  ll n, k;
  cin >> n >> k;
  
  ll a[n+1], b[n+1];
  
  FOR(i,1,n) cin >> a[i];
  FOR(i,1,n) cin >> b[i];
  
  ll start = 0, end = (ll)(2*(1e9));
  while( start <= end ) {    
    ll mid = ( start + end )/2;
    double diff = k;
    FOR(i,1,n)
      diff += min(0.0,b[i] - mid*1.0*a[i]);
    if( diff >= 0 )
      start = mid+1;
    else
      end = mid-1;
  }
  
  cout << end;
}
