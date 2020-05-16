#include <bits/stdc++.h>
typedef long long ll;
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
  ll t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    vector<ll> v;
    FOR(i,1,n) {
      ll x; cin >> x;
      v.pb(x);
    }
    sort(all(v));

    ll cur = 0, ans = 0;
    FOR(i,0,n-1) {
      cur++;
      if (cur == v[i]) {
        ans++;
        cur = 0;
      }
    }

    cout << ans << '\n';
  }
}
