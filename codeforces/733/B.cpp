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

int main() {
  ll n; cin >> n;
  ll L = 0, R = 0;
  
  vector< pair<ll,ll> > v;
  
  FOR(i,1,n) {
    ll l, r;
    cin >> l >> r;
    
    L += l; R += r;
    v.pb( {l,r} );
  }
  
  ll cur = abs(L-R), ans = 0;
  
  FOR(i,0,n-1) {
    ll newL = L - v[i].F + v[i].S;
    ll newR = R - v[i].S + v[i].F;
    
    if( cur < abs(newL-newR) ) {
      cur = abs(newL-newR);
      ans = i+1;
    }
  }
  
  cout << ans;
}
