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
    string s; cin >> s;

    ll start = 0, ans = INT_MAX;
    map<char, ll> idx;
    FOR(end,0,s.size()-1) {
      idx[s[end]]++;
      
      while (true) {
        bool has = true;
        FOR(c,'1','3') if (idx[c] == 0) has = false;
        if (!has) break;
        ans = min(ans, end - start + 1);
        if (start < end && idx[s[start]] > 1) {
          idx[s[start]]--;
          start++;
        } else {
          break;
        }
      }
    }

    if (ans == INT_MAX) ans = 0;
    cout << ans << '\n';
  }
}
