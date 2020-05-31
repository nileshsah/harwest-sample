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
    string s; cin >> s;
    s = " " + s;

    vector<ll> prefix(s.size() + 1, 0);

    FOR(i,1,s.size()-1) {
      prefix[i] += prefix[i - 1];
      if (s[i] == '0') prefix[i]++;
    }

    ll ans = prefix[s.size() - 1];
    FOR(i,1,s.size()-1) {
      ll l = i - prefix[i];
      ll r = (prefix[s.size() - 1] - prefix[i]);
      ans = min(ans, l + r); 

      ll a = prefix[i];
      ll b = (s.size() - 1 - i) - r;
      ans = min(ans, a + b);
    }

    cout << ans << '\n';
  }
}
