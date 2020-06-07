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
  ll n; cin >> n;
  map<ll,set<ll>> pos;

  FOR(i,1,n) {
    ll x; cin >> x;
    pos[x].insert(i);
    pos[x].insert(i + n);
  }

  vector<ll> col(n + 10, 0);
  FOR(i,1,n) {
    ll x; cin >> x;
    ll y = *pos[x].lower_bound(i);
    col[y - i]++;
  }

  ll ans = 0;
  for(ll x : col) ans = max(ans, x);
  cout << ans;
}
