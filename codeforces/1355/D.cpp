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
  ll n, s;
  cin >> n >> s;

  ll val = s - (n - 1);
  ll left = s - val;

  if (n >= val || (s - n) >= val) {
    cout << "NO";
    return 0;
  }

  cout << "YES\n";
  FOR(i,1,left) cout << 1 << ' ';
  cout << val << '\n' << n;
}
