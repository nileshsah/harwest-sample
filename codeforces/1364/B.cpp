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
  BOOST;
  ll t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    vector<ll> ans;

    FOR(i,0,n-1) {
      ll x; cin >> x;
      ll sz = ans.size();
      if (ans.size() < 2) {
        ans.pb(x);
      } else {
        bool pos = (ans[sz - 1] < ans[sz - 2]) && (x < ans[sz - 1]);
        pos |= (ans[sz - 1] > ans[sz - 2]) && (x > ans[sz - 1]);
        if (pos) ans.pop_back();
        ans.pb(x);
      }
    }

    cout << ans.size() << '\n';
    for (ll x : ans) cout << x << ' ';
    cout << '\n';
  }
}
