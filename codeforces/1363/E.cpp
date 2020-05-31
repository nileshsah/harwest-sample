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

const ll MaxVal = 5 * 100000;

ll tree[3][MaxVal + 1] = {0};

void update(ll t, ll x, ll y) {
   while (x <= MaxVal) {
     tree[t][x] += y;
     x += (x&-x);
   }
}

ll read(ll t, ll x) {
  ll sum = 0;
  while (x > 0) {
    sum += tree[t][x];
    x -= (x&-x);
  }
  return sum;
}

ll in[MaxVal] = {0};
ll out[MaxVal] = {0};

vector<ll> v[MaxVal];
ll n;
ll a[MaxVal]; 
bool b[MaxVal], c[MaxVal];

ll clk = 0;
void dfs(ll nd, ll p) {
  in[nd] = ++clk;
  for(ll x : v[nd]) {
    if (x == p) continue;
    dfs(x, nd);
  }
  out[nd] = ++clk;
}

int main() {
  BOOST;
  cin >> n;
  vector<pair<ll,ll>> arr;
  FOR(i,1,n) {
    cin >> a[i] >> b[i] >> c[i];
    arr.pb({a[i], i});
  }

  FOR(i,1,n-1) {
    ll x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  
  dfs(1, -1);

  FOR(i,1,n) {
    if (b[i] == c[i]) continue;
    update(b[i], in[i], +1);
  }
  sort(all(arr));

  ll ans = 0;
  for(auto it : arr) {
    ll nd = it.S;
    if (read(2, in[nd]) > 0) continue;
    ll zero = read(0, out[nd]) - read(0, in[nd] - 1);
    ll one = read(1, out[nd]) - read(1, in[nd] - 1);
    ll minVal = min(one, zero);

    ans += 2 * minVal * a[nd];
    //cerr << "k * a = " << minVal << " " << a[nd] << " for " << nd << '\n';

    update(0, in[nd], -minVal);
    update(1, in[nd], -minVal);
    update(2, in[nd], +1);
    update(2, out[nd] + 1, -1);
  }

  if (read(0, MaxVal - 1) + read(1, MaxVal - 1) > 0) {
    cout << -1;
    return 0;
  }

  cout << ans;
}
