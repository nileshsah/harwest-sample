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

ll MaxVal = 2*100001;
ll tree[2*100005];

void update( ll idx, ll val ) {
  while( idx < MaxVal ) {
    tree[idx] += val;
    idx += ( idx &(-idx) );
  }
}

ll read( ll idx ) {
  ll sum = 0;
  while( idx > 0 ) {
    sum += tree[idx];
    idx -= ( idx & (-idx) );
  }
  return sum;
}


int main() {
  ll n; cin >> n;
  
  map< ll, vector< pair<ll,ll> > > xarr, yarr;
  map< ll, vector< pair<char, pair<ll,ll> > > > event;
  
  map<ll,ll> HashVal;
  set<ll> all;
  
  FOR(i,1,n) {
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    if( x2 < x1 ) swap( x1, x2 );
    if( y2 < y1 ) swap( y1, y2 );
    
    if( x1 == x2 )
      xarr[x1].pb( { y1, y2 } );
    else 
      yarr[y1].pb( { x1, x2 } );
    
    all.insert(y1); all.insert(y2);
    all.insert(x2); all.insert(x1);
  }
  
  int ptr = 2;
  for( auto y : all )
    HashVal[y] = ptr++;
   
  ll ans = 0;
  
  for( auto p : xarr ) {
    auto &v = p.S;
    sort( all(v) );
    
    auto cur = v[0];
    
    FOR(i,1,v.size()-1) {
      if( v[i].F > cur.S ) {
        event[ cur.F ].pb( { 'L', { p.F, 0 } } );
        event[ cur.S+1 ].pb( { 'R', { p.F, 0 } } );
        ans += cur.S - cur.F + 1;
        cur = v[i];
      }
      else 
        cur.S = max( cur.S, v[i].S );
    }

    ans += cur.S - cur.F + 1;
    event[ cur.F ].pb( { 'L', { p.F, 0 } } );
    event[ cur.S+1 ].pb( { 'R', { p.F, 0 } } );
  }
  
  
  for( auto p : yarr ) {
    auto &v = p.S;
    sort( all(v) );
    
    auto cur = v[0];
    
    FOR(i,1,v.size()-1) {
      if( v[i].F > cur.S ) {
        event[p.F].pb( { 'V', cur } );
        ans += cur.S - cur.F + 1;
        cur = v[i];
      }
      else 
        cur.S = max( cur.S, v[i].S );
    }
    
    ans += cur.S - cur.F + 1;
    event[p.F].pb( { 'V', cur } );
  }
  
  
  for( auto p : event ) 
    for( auto q : p.S ) {
      if( q.F == 'L' ) 
        update( HashVal[q.S.F], 1 );
      else if( q.F == 'R' )
        update( HashVal[q.S.F], -1 );
      else if( q.F == 'V' )
        ans -= read( HashVal[q.S.S] ) - read( HashVal[q.S.F]-1 );
    }
    
  
  cout << ans;
}
