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
    ll a[n + 1], b[n + 1];
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];

    bool pos = true;
    vector<pair<ll,ll>> A, B;
    FOR(start,1,n/2) {
      ll end = n - start + 1;
      if (a[start] > a[end]) swap(a[start], a[end]);
      if (b[start] > b[end]) swap(b[start], b[end]);
      A.pb({a[start], a[end]});
      B.pb({b[start], b[end]});
    }
   
    sort(all(A));
    sort(all(B));

    pos &= (A == B);
    if (n%2) pos &= (a[(n + 1)/2] == b[(n + 1)/2]);

    if(pos) cout << "Yes\n";
    else cout << "No\n";
  }
}
