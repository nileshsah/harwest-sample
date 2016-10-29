#include <bits/stdc++.h>
typedef int ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) ; //cerr << "[DEBUG] " << #x << " = " << x << endl;
#define F first
#define S second
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

#define H 0
#define V 1

#define L 2*r
#define R 2*r+1

struct node {
  ll l, r;
  ll val, lazy;
}tree[2][1600005];

void construct( pair<ll,ll> p, bool d, ll r = 1  ) {
  node &ptr = tree[d][r];
  
  ptr.l = p.F, ptr.r = p.S;
  ptr.lazy = -1;
  
  if( p.F == p.S ) {
    ptr.val = 0;
  }
  else {
    ll mid = ( ptr.l + ptr.r )/2;
    construct( { p.F, mid }, d, L );
    construct( { mid+1, p.S }, d, R );
    
    ptr.val = max( tree[d][L].val, tree[d][R].val );
  }
}

void print( bool d, ll r ) {
  return;
  
  node &ptr = tree[d][r];
  
  if( d == 0 ) cerr << "[H] ";
  else cerr << "[V] ";
  cerr << "R: " << "[ " << ptr.l << " , " << ptr.r << " ] "
       << "VAL: " << ptr.val << '\n';
}

void lazyme( bool d, ll r ) {
  node &ptr = tree[d][r];
  
  if( ptr.lazy != -1 ) {
    ptr.val = max( ptr.val, ptr.lazy );
    
    if( ptr.r != ptr.l ) {
      tree[d][L].lazy = max( tree[d][L].lazy, ptr.lazy );
      tree[d][R].lazy = max( tree[d][R].lazy, ptr.lazy );
    }
    
    ptr.lazy = -1;
  }
}

void update( ll x, ll y, ll val, bool d, ll r = 1 ) {
  node &ptr = tree[d][r];
  
  lazyme(d,r);
  
  if( ptr.r < x || ptr.l > y )
    return;
  
  if( ptr.l >= x && ptr.r <= y ) {
    ptr.lazy = max( ptr.lazy, val );
    lazyme(d,r);
  }
  else {
    update( x, y, val, d, L );
    update( x, y, val, d, R );
    
    ptr.val = max( tree[d][L].val, tree[d][R].val );
  }
  
  print(d,r);
}

node query( ll x, ll y, ll d, ll r = 1 ) {
  
  print(d,r);
  
  node &ptr = tree[d][r];
  lazyme(d,r);
  
  if( ptr.l >= x && ptr.r <= y )
    return ptr;
  
  ll mid = ( ptr.r + ptr.l )/2;
  if( y <= mid )
    return query( x, y, d, L );
  if( x > mid )
    return query( x, y, d, R );
  
  node qr = query( x, y, d, R );
  node ql = query( x, y, d, L );
  
  node ret;
  ret.l = ql.l; ret.r = qr.r;
  ret.lazy = -1;
  ret.val = max( qr.val, ql.val );
  
  return ret;
}

int main() {
  BOOST;
  ll n, m;
  cin >> n >> m;
  
  set<ll> arr;
  vector< pair< pair<ll,ll>, char > > Q;
  map< pair< pair<ll,ll>, char >, bool > exists;
  
  map<ll,ll> hash, revHash;
  
  arr.insert(0);
  
  FOR(i,1,m) {
    ll x, y; char c;
    cin >> x >> y >> c;
    
    Q.pb( { { x, y }, c } );
    
    arr.insert(y);
    arr.insert(x);
  }  
  
  ll cnt = 0;
  for( ll x : arr ) hash[x] = ++cnt, revHash[cnt] = x;
  construct( {1,cnt}, H );
  construct( {1,cnt}, V );
    
  for( auto q : Q ) {
    ll x = q.F.F, y = q.F.S;
    char c = q.S;
    
    if( exists[q] ) {
      cout << "0\n";
      continue;
    }
    
    exists[q] = 1;
    
    if( c == 'U' ) {
      debug( hash[y] );
      ll up = revHash[ query( hash[x], hash[x], V ).val ];
      cout << y-up << '\n';
      debug(up);
      update( hash[up], hash[y], hash[x], H );
    }
    else if( c == 'L' ) {
      debug( hash[x] );
      ll left = revHash[ query( hash[y], hash[y], H ).val ];
      cout << x-left << '\n';
      debug(left);
      update( hash[left], hash[x], hash[y], V );
    }   
  }
    
}
