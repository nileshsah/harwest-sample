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
  ll n, a, b, T;
  cin >> n >> a >> b >> T;
  
  string s; cin >> s;
  ll prefix[n+1];
  memset( prefix, 0, sizeof prefix );
  
  ROF(i,n-1,0)
    prefix[i] = prefix[i+1] + a + ( s[i] == 'w' )*b + 1;
  
  ll ans = 0, left = T - 1 - ( s[0] == 'w' )*b;
  
  if( left < 0 ) {
    cout << 0;
    return 0;
  }
  ans = 1;
  
  FOR(i,1,n-1) {
    if( left < 0 )
      break;
    ll start = i, end = n-1;
    while( start <= end ) {
      ll mid = ( start + end )/2;
      ll l = left - min( (i-1)*a, (n-mid)*a );
      if( prefix[mid] > l )
        start = mid+1;
      else
        end = mid-1;
    }
    //~ cerr << "R: " << i << ' ' << n - start << '\n';
    ans = max( ans, i + n - start );
    left -= 1 + ( s[i] == 'w' )*b + a;
  }
  
  cout << ans;
}
