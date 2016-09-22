#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vector<ll> v[100005];
ll to[100005];
bool explore[1000005];
bool given[1000005];
ll in[1000005];
ll depth[1000005];

void depthdfs( ll x, ll d ) {
  depth[x] = d;
  
  for( ll q : v[x] )
    depthdfs( q, d+1 );
}

set< pair<ll,ll> > idx;

bool dfs( ll x, ll p ) {
  explore[x] = 1;
  //~ cerr << "R: " << x << ' ' << curDepth << '\n';
  if( !( to[x] == x || to[x] == p || to[x] == to[p] ) )
    return 0;
  
  if( given[x] )
   idx.insert( { depth[x], x } );
  
  bool ret = 1;
  for( ll q : v[x] )
    ret &= dfs( q, x );
  
  return ret;  
}

int main() {
  ll n, m;
  cin >> n >> m;
  
  FOR(i,1,m) {
    ll x, y;
    cin >> x >> y;
    in[y]++;
    v[x].pb(y);
  }
  
  FOR(i,1,n) {
    ll x; cin >> x;
    to[i] = x;
    given[x] = 1;
  }
  
  FOR(i,1,n)
    if( !in[i] )
      depthdfs(i,1);
  
  vector<ll> ans;
  
  FOR(i,1,n)
    if( !explore[i] && !in[i] ) {
      if( !dfs( i, -1 ) ) {
        cout << "-1";
        return 0;
      }
      while(!idx.empty()) {
        ans.pb( idx.rbegin()->S );
        idx.erase(--idx.end());
      }
    }
  
  cout << ans.size() << '\n';
  for( ll x : ans )
    cout << x << '\n'; 
  
    
}
