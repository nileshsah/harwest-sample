#include <bits/stdc++.h>
typedef int ll;
#define repVector(v)  for( auto it = v.begin(); it != v.last(); it++ )
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl;
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
#define OUTFILE freopen("output.out","w",stdout)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main() {
  ll n, q;
  cin >> n >> q;
  
  int till[105] = {0};
  
  FOR(Q,1,q) {
    ll t, k, d;
    cin >> t >> k >> d;
    vector<ll> to;
    
    FOR(i,1,n) {
      if( (int)to.size() == k )
        break;
      if( till[i] < t )
        to.pb(i);
    }
    
    if( (int)to.size() != k )
      cout << -1 << '\n';
    else {
      ll sum = 0;
      for( ll x : to ) {
        sum += x;
        till[x] = t+d-1;
      }
      cout << sum << '\n';
    }
  }
}
