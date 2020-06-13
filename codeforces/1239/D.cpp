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

const int MAXN = 1000000;

ll n, m;
vector<ll> g[MAXN + 5];
vector<ll> gr[MAXN + 5];
set<ll> gc[MAXN + 5];
ll tout[MAXN + 5] = {0};
ll comp[MAXN + 5] = {0};
bool explored[MAXN + 5] = {0};

ll now = 0;
void dfs(ll pos) {
  now++;
  explored[pos] = true;
  for(ll x : g[pos]) {
    if(explored[x]) continue;
    dfs(x);
  }
  tout[pos] = ++now;
}

ll sccnum = 0;
void scc(ll pos) {
  explored[pos] = true;
  comp[pos] = sccnum;
  for(ll x : gr[pos]) {
    if(explored[x]) continue;
    scc(x);
  }
}

void reset(ll n) {
  now = sccnum = 0;
  FOR(i,0,n+1) {
    g[i].clear();
    gr[i].clear();
    gc[i].clear();
    tout[i] = comp[i] = explored[i] = 0;
  }
}

void solveSCC() {
  cin >> n >> m;
  reset(n);

  FOR(i,1,m) {
    ll x, y;
    cin >> x >> y;
    g[x].pb(y);
    gr[y].pb(x);
  }
  
  FOR(i,1,n) if(!explored[i]) dfs(i);
  vector<pair<ll,ll>> col;
  FOR(i,1,n) {
    col.pb({tout[i],i});
    explored[i] = false;
  }
  
  sort(col.rbegin(), col.rend());
  
  for(auto it : col) {
    ll x = it.S;
    if(explored[x]) continue;
    sccnum++;
    scc(x);
  }
  
  FOR(i,1,n) for(ll j : g[i]) if(comp[i] != comp[j]) {
    gc[comp[i]].insert(comp[j]);
  }
  
  // END OF SCC GRAPH CONDENSATION  
}

int main() {
  BOOST;
  ll t; cin >> t;
  while (t--) {
    solveSCC();

    if (sccnum == 1) {
      cout << "No\n";
      continue;
    }

    vector<ll> indeg(sccnum + 1, 0);
    FOR(i,1,sccnum) for(ll x : gc[i]) indeg[x]++;
    set<ll> candid, jury;
    FOR(i,1,sccnum) if (indeg[i] == 0) candid.insert(i); else jury.insert(i);
    if (jury.empty()) {
      jury.insert(*candid.begin());
      candid.erase(candid.begin());
    }

    vector<ll> cp, jp;
    FOR(i,1,n) if (candid.count(comp[i])) cp.pb(i); else jp.pb(i);
    cout << "Yes\n";
    cout << jp.size() << " " << cp.size() << '\n';
    for (ll x : jp) cout << x << ' ';
    cout << '\n';
    for (ll x : cp) cout << x << ' ';
    cout << '\n';
  }
}
