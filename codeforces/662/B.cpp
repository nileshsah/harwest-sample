#include <bits/stdc++.h>
typedef long long ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl;
#define F first
#define S second
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll n;
int explore[100005];
vector<pair<ll,ll>> v[100005];
vector<ll> heap[2];

bool dfs( ll x, bool s, char c ) {
  if( explore[x] != -1 )
    return explore[x] == s;
  explore[x] = s;
  heap[s].pb(x);
  bool ret = 1;
  for( auto q : v[x] )
    ret &= dfs( q.F, q.S == c ? s : !s, c );
  return ret;
}

vector<ll> solve( char c ) {
  memset( explore, -1, sizeof explore );
  vector<ll> ans;
  
  FOR(i,1,n)
    if( explore[i] == -1 ) {
      heap[0].clear(); heap[1].clear();
      if( !dfs( i, 0, c ) )
        return vector<ll>(n+1,-1);
      int smallestHeap = 1;
      if( heap[0].size() <= heap[1].size() )
        smallestHeap = 0;
      for( ll x : heap[smallestHeap] )
        ans.pb(x);
    }
  return ans;
}

int main() {
  ll m;
  cin >> n >> m;
    
  FOR(i,1,m) {
    ll x, y; char c;
    cin >> x >> y >> c;
    v[x].pb({y,c});
    v[y].pb({x,c});
  }
  
  auto R = solve('R');
  auto B = solve('B');
    
  if( R.size() > B.size() )
    R = B;
  if( (int)R.size() > n ) {
    cout << -1;
    return 0;
  }
  
  cout << R.size() << '\n';
  for( ll x : R )
    cout << x << ' ';
}
