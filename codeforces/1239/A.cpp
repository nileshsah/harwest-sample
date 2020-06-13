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

const ll MAXN = 100000;
const ll MOD = (ll)(1e9) + 7LL;

ll dp[MAXN + 5][2][3];

ll modpow(ll x, ll y) {
  ll ans = 1;
  while (y > 0) {
    if (y&1) ans = (ans * x) % MOD;
    x = (x * x) % MOD;
    y /= 2;
  }
  return ans;
}

int main() {
  memset(dp, 0, sizeof dp);
  dp[1][0][1] = dp[1][1][1] = 1;
  FOR(i,1,MAXN) {
    FOR(j,0,1) {
      bool c = (j == 1);
      FOR(r,1,2) dp[i + 1][c][1] += dp[i][!c][r];
      dp[i + 1][c][2] += dp[i][c][1];

      FOR(r,1,2) dp[i + 1][c][r] %= MOD;
    }
  }

  ll n, m;
  cin >> n >> m;
  
  if(n < m) swap(n, m);

  ll pos = 0, col = 0;
  FOR(i,1,2) {
    pos += dp[n][0][i] + dp[n][1][i];
    col += dp[m][0][i] + dp[m][1][i];
    pos %= MOD; col %= MOD;
  }

  pos = pos - 2 + col;
  if (pos < 0) pos += MOD;

  cout << pos % MOD;
}
