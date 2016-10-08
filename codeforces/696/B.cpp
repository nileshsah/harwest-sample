#include <bits/stdc++.h>
typedef int ll;
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
ll parent[100005] = {0};
ll sz[100005] = {0};

double ans[100005];
double fact[100005];


void rec( ll x, ll p, double eval ) {
  
  ll s = sz[p] - sz[x] - 1;  
  ans[x] = eval + s / 2.0 + 1;
  
  for( ll q : v[x] )
    rec( q, x, ans[x] );
}

ll dfs( ll x, ll p ) {
  sz[x] = 1;
  for( ll q : v[x] )
    if( p != q )
      sz[x] += dfs( q, x );
  return sz[x];
}

int main() {
  ll n; cin >> n;
  
  FOR(i,2,n) {
    cin >> parent[i];
    v[ parent[i] ].pb(i);
  }
  
  dfs(1,-1);
  
  ans[1] = 1.0;
  
  for( ll q : v[1] )
    rec( q, 1, 1.0 );
  
  FOR(i,1,n)
    printf("%0.6lf ", ans[i]);
  
}
