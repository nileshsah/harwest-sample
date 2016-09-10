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

vector<ll> adj[3005];
vector<ll> adjR[3005];

ll dist[3005][3005];
ll distR[3005][3005];
set< pair<ll,ll> > nodeR[3005], node[3005];

ll n;

void bfs1( ll p ) {
  
  queue<ll> Q;
  Q.push(p);
  dist[p][p] = 0;
  
  while(!Q.empty()) {
    ll ptr = Q.front();
    ll d = dist[p][ptr];
    Q.pop();
    
    node[p].insert( { d, ptr } );
    while( node[p].size() > 3 )
      node[p].erase( node[p].begin() );

    for( ll i : adj[ptr] )
      if( dist[p][i] > d+1 ) {
        Q.push(i);
        dist[p][i] = d+1;
      }
  }
  
}
void bfs2( ll p ) {
  
  queue<ll> Q;
  Q.push(p);
  distR[p][p] = 0;
  
  while(!Q.empty()) {
    ll ptr = Q.front();
    ll d = distR[p][ptr];
    Q.pop();
    
    nodeR[p].insert( { d, ptr } );
    while( nodeR[p].size() > 3 )
      nodeR[p].erase( nodeR[p].begin() );

    for( ll i : adjR[ptr] )
      if( distR[p][i] > d+1 ) {
        Q.push(i);
        distR[p][i] = d+1;
      }
  }
  
}

int main() {
  BOOST;
  ll m;
  cin >> n >> m;
    
  FOR(i,1,m) {
    ll u, v;
    cin >> u >> v;
    
    adj[u].pb(v);
    adjR[v].pb(u);
  }
  
  FOR(i,1,n) FOR(j,1,n) dist[i][j] = distR[i][j] = INT_MAX;
  
  FOR(i,1,n) {
    bfs1( i );
    bfs2( i );
  }
  
  ll ans = -1;
  vector<ll> w;
  
  FOR(i,1,n) FOR(j,1,n)
      if( i != j && dist[i][j] != INT_MAX ) {
        for( auto x : nodeR[i] ) for( auto y : node[j] )
            if( x.S != i && y.S != j && x.S != j && y.S != i && y.S != x.S ) {
              if( dist[i][j] + x.F + y.F > ans ) {
                ans = dist[i][j] + x.F + y.F;
                w.clear();
                w.pb(x.S); w.pb(i); w.pb(j); w.pb(y.S);
              }
            }
      }
  
  debug(ans);
  
  for( ll x : w )
    cout << x << ' ';
  
}
