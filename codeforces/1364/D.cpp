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

const ll MAXN = 100000;

ll n, m, k;
vector<ll> v[MAXN + 5];

bool hasCycle = false;
deque<ll> cur, cval;

bool in[MAXN + 5] = {0};
bool explored[MAXN + 5] = {0};
map<ll,ll> mypos;

void cydfs(ll nd, ll p) {
  cur.pb(nd);
  mypos[nd] = cur.size() - 1;
  for (ll x : v[nd]) {
    if (!hasCycle && x != p && in[x]) {
      ll len = cur.size() - mypos[x];
      if (cval.empty() || cval.size() > len) {
        deque<ll> nc(cur);
        while (nc.front() != x) {
          nc.pop_front();
        }
        cval = nc;
      }
      if (len <= k) hasCycle = true;
    }
  }

  in[nd] = true;
  for (ll x : v[nd]) {
    if (x == p || in[x] || explored[x]) continue;
    cydfs(x, nd);
  }

  in[nd] = false;
  explored[nd] = true;
  cur.pop_back();
}

vector<ll> col[2];
void tree(ll nd, ll p, bool bit) {
  explored[nd] = true;
  col[bit].pb(nd);
  for (ll x : v[nd]) {
    if (x == p || explored[x]) continue;
    tree(x, nd, !bit);
  }
}

int main() {
  BOOST;
  cin >> n >> m >> k;
  FOR(i,1,m) {
    ll x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }

  ll need = (k + 1) / 2 - 1;

  if (m == n - 1) {
    tree(1, -1, 0);
    if (col[0].size() < col[1].size()) swap(col[0], col[1]);
    assert (col[0].size() >= (k + 1)/2);
    cout << 1 << '\n';
    FOR(i,0,need) cout << col[0][i] << ' ';
    return 0;
  }

  memset(explored, 0, sizeof explored);
  cydfs(1, -1);
  if (hasCycle) {
    cout << 2 << '\n';
    cout << cval.size() << '\n';
    for (ll x : cval) cout << x << " ";
    return 0;
  } else {
    assert (cval.size() > k);

    cout << 1 << '\n';
    FOR(i,0,need) {
      cout << cval.front() << ' ';
      if (i == need) break;
      cval.pop_front();
      cval.pop_front();
    }
  }

}
