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
    set<ll> row, col;
    ll n, m;
    cin >> n >> m;

    FOR(i,1,n) row.insert(i);
    FOR(j,1,m) col.insert(j);

    bool a[n + 1][m + 1];

    FOR(i,1,n) FOR(j,1,m) {
      cin >> a[i][j];
      if (a[i][j]) {
        row.erase(i);
        col.erase(j);
      }
    }

    bool isAshish = true;
    while (!row.empty() && !col.empty()) {
      row.erase(row.begin());
      col.erase(col.begin());
      isAshish = !isAshish;
    }

    if (isAshish) cout << "Vivek" << '\n';
    else cout << "Ashish" << '\n';
  }
}
