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

    ll odd = 0, even = 0;
    FOR(i,1,n) {
      ll p; cin >> p;
      if (p%2) odd++;
      else even++;
    }

    if (odd == 0) {
      cout << "No\n";
      continue;
    }
    x--; odd--;
    while (odd >= 2 && x >= 2) {
      x -= 2;
      odd -= 2;
    }
    if (even >= x) cout << "Yes\n";
    else cout << "No\n";
  }
}
