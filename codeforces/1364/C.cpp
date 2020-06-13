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
  ll a[n + 1], b[n + 1];
  memset(b, -1, sizeof b);

  ll maxVal = -1;
  FOR(i,1,n) {
    cin >> a[i];
    maxVal = max(maxVal, a[i]);
  }
  
  set<ll> need;
  FOR(i,0,maxVal-1) need.insert(i);
  
  FOR(i,2,n) if (a[i] > a[i - 1]) {
    b[i] = a[i - 1];
    need.erase(a[i - 1]);
  }
  
  FOR(i,1,n) {
    if (b[i] != -1) {
      // do nothing
    } else if (need.empty()) {
      b[i] = n + 100;
    } else {
      b[i] = *need.begin();
      need.erase(need.begin());
    }
    if (!need.empty() && *need.begin() < a[i]) {
      cout << -1;
      return 0;
    }
  }

  FOR(i,1,n) cout << b[i] << ' ';
}
