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

struct node {
  ll to, w;
  bool tofill;
  
  node( ll _to, ll _w, bool _tofill ) {
    to = _to;
    w = _w;
    tofill = _tofill;
  }
};

ll D[1005][1005];
vector<node> v[1005];

int main() {
  ll n, m, L, start, end;
  cin >> n >> m >> L >> start >> end;
  
  FOR(i,1,m) {
    ll x, y, w; bool lab = 0;
    cin >> x >> y >> w;
    if( w == 0 ) w = 1, lab = 1;
    v[x].pb( node(y,w,lab) );
    v[y].pb( node(x,w,lab) );
  }
  
  set< pair<ll,ll> > idx;
  vector<ll> DS(n+1,LONG_MAX), DT(n+1,LONG_MAX);
  
  DS[start] = 0;
  idx.insert( {0,start} );
  
  while(!idx.empty()) {
    ll ptr = idx.begin()->S;
    ll dist = idx.begin()->F;
    idx.erase(idx.begin());
        
    for( node x : v[ptr] ) {
      if( DS[x.to] > dist + x.w ) {
        idx.erase( { DS[x.to], x.to } );
        DS[x.to] = dist + x.w;
        idx.insert( { DS[x.to], x.to } );
      }
    }
  }
    
  DT[end] = 0;
  idx.insert( {0,end} );
  
  while(!idx.empty()) {
    ll ptr = idx.begin()->S;
    ll dist = idx.begin()->F;
    idx.erase(idx.begin());

    //~ cerr << "R: " << ptr << " D: " << dist << '\n';
        
    for( node x : v[ptr] ) {
      if( x.tofill ) {
        x.w = max( 1LL, L-dist-DS[x.to] );
        D[ptr][x.to] = x.w;
      }
      if( DT[x.to] > dist + x.w ) {
        idx.erase( { DT[x.to], x.to } );
        DT[x.to] = dist + x.w;
        idx.insert( { DT[x.to], x.to } );
        
      }
    }
  }
  
  debug(DT[start]);
  if( DT[start] != L ) {
    cout << "NO";
    return 0;
  }
  
  cout << "YES\n";
  FOR(i,0,n-1)
    for( node x : v[i] ) {
      if( x.to < i ) continue;
      cout << i << ' ' << x.to << ' ';
      if( D[i][x.to] or D[x.to][i] ) cout << max( D[x.to][i], D[i][x.to] );
      else cout << x.w;
      cout << '\n';
    }
}
