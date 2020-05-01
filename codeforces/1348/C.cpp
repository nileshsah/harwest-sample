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
    ll n, k;
    cin >> n >> k;
    string s; cin >> s;

    sort (all(s));

    if (s[0] == s.back()) {
      ll len = (s.size() / k) + (s.size() % k > 0);
      string ans; FOR(i,1,len) ans.pb(s[0]);
      cout << ans << '\n';
      continue;
    }

    set<char> col;
    FOR(i,0,k-1) {
      col.insert(s[i]);
    }

    if (*col.begin() != *col.rbegin()) {
      cout << *col.rbegin() << '\n';
      continue;
    }

    col.clear();
    FOR(i,0,s.size()-1) col.insert(s[i]);

    if (col.size() == 2) {
      char fi = *col.begin(), se = *col.rbegin();
      ll fc = 0, sc = 0;
      FOR(i,0,s.size()-1) {
        if (s[i] == fi) fc++;
        else sc++;
      }
      if (fc % k == 0 && fc / k == 1) {
        ll l1 = fc / k;
        ll l2 = (sc / k) + (sc % k > 0);
        cout << string(l1,fi) + string(l2,se) << '\n';
        continue;
      }
    }

    string ans = string(1,s[0]);
    FOR(i,k,s.size()-1) ans.pb(s[i]);
    cout << ans << '\n';
  }
}
