#include <bits/stdc++.h>
typedef int ll;
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

ll a[1005];
ll ans[10005];

int main() {
  ll t; cin >> t;
  while (t--) {
    ll n, k; 
    cin >> n >> k;
    set<ll> idx;
    FOR(i,1,n) {
      cin >> a[i];
      idx.insert(a[i]);
    }
    
    FOR(i,1,n) if(idx.size() < k && idx.find(i) == idx.end()) idx.insert(i);
    if (idx.size() != k) {
      cout << -1 << '\n';
      continue;
    }

    ll ptr = 1, cur = 1;
    while (ptr <= n) {
      for (ll i : idx) {
        if (ptr <= n && a[ptr] == i) ptr++;
        ans[cur] = i;
        cur++;
      }
    }
    cout << cur - 1 << '\n';
    FOR(i,1,cur-1) cout << ans[i] << ' ';
    cout << '\n';
  }
}
