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

bool used[100005];
char c[100005];
ll sz[100005];
vector<ll> v[100005];

void dfs( ll x, ll p ) {
  sz[x] = 1;
  for( ll q : v[x] )
    if( q != p && !used[q] )
      dfs( q, x ), sz[x] += sz[q];
}

ll findRoot( ll x, ll p, ll sub ) {
  for( ll q : v[x] )
    if( q != p && !used[q] && sz[q] > sub/2 )
      return findRoot( q, x, sub );
  return x;
}

void solve( ll x, char cur = 'A' ) {
  if( cur > 'Z' ) {
    cout << "Impossible!";
    exit(0);
  }
  
  dfs( x, -1 );
  ll centroid = findRoot( x, -1, sz[x] );
  used[centroid] = 1;
  c[centroid] = cur;
    
  for( ll q : v[centroid] )
    if( !used[q] )
      solve( q, cur+1 );
}

int main() {
  ll n; cin >> n;
  
  FOR(i,1,n-1) {
    ll x, y;
    cin >> x >> y;
  
    v[x].pb(y);
    v[y].pb(x);
  }
  
  solve(1);
    
  FOR(i,1,n)
    cout << c[i] << ' ';
}
