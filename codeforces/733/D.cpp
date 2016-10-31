#include <bits/stdc++.h>
typedef long long ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl;
#define F first
#define S second
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

map< pair<ll,ll>, pair<ll,ll> > m;

ll MIN( ll a, ll b, ll c ) {
  return min( min(a,b), c );
}

int main() {
  ll n; cin >> n;
  double ans1 = 0, ans2 = 0;
  ll i1, i21, i22;
  
  FOR(i,1,n) {
    ll a, b, c;
    cin >> a >> b >> c;
    
    double r = MIN(a,b,c)*0.5;
    if( r > ans1 )
      ans1 = r, i1 = i;
    
    if( MIN( a, b, c+m[{a,b}].F )*0.5 > ans2 ) {
      ans2 = MIN( a, b, c+m[{a,b}].F )*0.5;
      i21 = i, i22 = m[{a,b}].S;
    }     
    if( MIN( b, c, a+m[{b,c}].F )*0.5 > ans2 ) {
      ans2 = MIN( b, c, a+m[{b,c}].F )*0.5;
      i21 = i, i22 = m[{b,c}].S;
    }     
    if( MIN( a, c, b+m[{a,c}].F )*0.5 > ans2 ) {
      ans2 = MIN( a, c, b+m[{a,c}].F )*0.5;
      i21 = i, i22 = m[{a,c}].S;
    }     
    
    if( c > m[{a,b}].F ) {
      m[{a,b}].F = c, m[{a,b}].S = i;
    }
    if( c > m[{b,a}].F ) {
      m[{b,a}].F = c, m[{b,a}].S = i;
    }
    
    if( a > m[{b,c}].F ) {
      m[{b,c}].F = a, m[{b,c}].S = i;
    }
    if( a > m[{c,b}].F ) {
      m[{c,b}].F = a, m[{c,b}].S = i;
    }
    
    if( b > m[{a,c}].F ) {
      m[{a,c}].F = b, m[{a,c}].S = i;
    }
    if( b > m[{c,a}].F ) {
      m[{c,a}].F = b, m[{c,a}].S = i;
    }
    
  }
  
  debug(ans1);
  debug(ans2);
  
  if( ans1 >= ans2 ) {
    cout << "1\n" << i1;
  }
  else {
    cout << "2\n" << i21 << ' ' << i22;
  }
}
