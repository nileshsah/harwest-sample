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

    vector<ll> a(n + 1), b(n + 1), v1, v2;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];
    bool pos = true;
    FOR(i,1,n) {
      if (b[i] == 0) v1.pb(a[i]);
      else if (b[i] == 1) v2.pb(a[i]);
    }

    if (!v1.empty() && !v2.empty()) pos = true;
    else if (v1.empty()) {
      ll last = -1;
      for (ll x : v2) if (x < last) pos = false;
      else last = x;
    } else if (v2.empty()) {
      ll last = -1;
      for (ll x : v1) if (x < last) pos = false;
      else last = x;
    }

    if(pos) cout << "Yes\n";
    else cout << "No\n";
  }
}
