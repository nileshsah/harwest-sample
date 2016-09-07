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

ll a[100005];
ll b[100005];

bool check( ll l, ll r, ll lc, ll rc ) {
  bool zero_allowed = 0;
  while( l <= r ) {
    a[l] += 10*lc; a[r] -= rc;
    lc = rc = 0;
    if( a[l] - a[r] > 9 ) {
      a[r] += 10;
      rc = 1;
    }
    if( a[l] > a[r] ) {
      a[l] -= 1;
      lc = 1;
    }
    //~ cerr << "R: " << l << ' ' << r << ' ' << a[l] << ' ' << a[r] << '\n';
 
    if( a[l] != a[r] || a[l] > 18 )
      return 0;
    if( a[l]%2 == 0 )
      b[l] = b[r] = a[l]/2;
    else
      b[l] = ( a[l]+1 )/2, b[r] = a[l]/2;
    
    if( zero_allowed == 0 && b[l] == 0 )
      return 0;
    if( b[l] + b[r] != a[l] )
      return 0;
    l++; r--; zero_allowed = 1;    
  }
  
  return ( lc == rc );
}

int main() {
  string s; cin >> s;
  FOR(i,0,s.size()-1)
    a[i] = s[i] - '0';
  
  if( check(0,s.size()-1,0,0) ) {
    FOR(i,0,s.size()-1)
      cout << b[i];
    return 0;
  }
  
  FOR(i,0,s.size()-1) 
    a[i] = s[i] - '0';
    
  if( s.size() > 1 && a[0] == 1 && check(1,s.size()-1,1,0) ) {
    FOR(i,1,s.size()-1)
      cout << b[i];
    return 0;
  }
  
  cout << 0;
}
