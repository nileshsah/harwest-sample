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
    ll n, x;
    cin >> n >> x;

    ll a[n + 1];
    FOR(i,1,n) cin >> a[i];

    ll last = -1, sum = 0, ans = 0;
    FOR(i,1,n) {
      sum += a[i];
      if (sum%x == 0 && last > -1) {
        ans = max(ans, i-last);
      } else if (sum%x != 0) {
        ans = max(ans, i);
      }
      if (sum%x != 0 && last == -1) last = i;
    }
    if (ans == 0) ans = -1; 
    cout << ans << '\n';
  }
}
