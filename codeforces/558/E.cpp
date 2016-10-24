#include <bits/stdc++.h>
typedef int ll;
#define repVector(v)  for( auto it = v.begin(); it != v.last(); it++ )
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

#define L 2*r
#define R 2*r+1

struct node {
  ll l, r;
  ll ch[26], lazy[26];
  
  node() {
    FOR(i,0,25) {
      ch[i] = 0;
      lazy[i] = -1;
    }
  }
}tree[4*100001];

char s[100005];

void construct( pair<ll,ll> p, ll r = 1 ) {
  node &ptr = tree[r];
  
  ptr.l = p.F; ptr.r = p.S;
  
  if( p.F == p.S ) {
    ptr.ch[ s[p.F]-'a' ]++;
  }
  else {
    ll mid = ( p.F + p.S )/2;
    construct( { p.F, mid }, L );
    construct( { mid+1, p.S }, R );
    
    FOR(i,0,25)
      ptr.ch[i] = tree[L].ch[i] + tree[R].ch[i];
  }
}

void lazyme( ll r, ll c ) {
  node &ptr = tree[r];
  
  if( ptr.lazy[c] != -1 ) {
    ptr.ch[c] = ptr.lazy[c] * ( ptr.r - ptr.l + 1 );
    
    if( ptr.l != ptr.r ) {
      tree[L].lazy[c] = ptr.lazy[c];
      tree[R].lazy[c] = ptr.lazy[c];
    }
    
    ptr.lazy[c] = -1;
  }
  
}

void update( ll x, ll y, ll val, ll c, ll r = 1 ) {
  node &ptr = tree[r];
  
  lazyme(r,c);
  
  if( ptr.l > y || ptr.r < x )
    return;
    
  if( ptr.l >= x && ptr.r <= y ) {
    ptr.lazy[c] = val;
    lazyme( r, c );
    return;
  }
  else if( ptr.l != ptr.r ) {
    update( x, y, val, c, L );
    update( x, y, val, c, R );
    
    ptr.ch[c] = tree[L].ch[c] + tree[R].ch[c];
  }
}

ll query( ll x, ll y, ll c, ll r = 1 ) {
  node &ptr = tree[r];
  
  lazyme( r, c );
  
  ll mid = ( ptr.l + ptr.r )/2;
  
  if( ptr.l >= x && ptr.r <= y )
    return ptr.ch[c];
  
  if( y <= mid )
    return query( x, y, c, L );
  if( x > mid )
    return query( x, y, c, R );
    
  return query( x, y, c, L ) + query( x, y, c, R );
}

void get( ll x, ll y, ll c, ll r = 1 ) {
  
  node &ptr = tree[r];
  lazyme(r,c);
  
  if( ptr.ch[c] == 0 )
    return;
  
  if( ptr.l == ptr.r ) {
    s[ptr.l] = c + 'a';
    return;
  }
  
  get( x, y, c, L );
  get( x, y, c, R );
}


int main() {
  BOOST;
  ll n, q;
  cin >> n >> q;
  
  FOR(i,1,n) cin >> s[i];
    
  construct( {1,n} );
  
  while(q--) {
    ll x, y, k;
    cin >> x >> y >> k;
    
    int freq[26] = {0};
    
    FOR(i,0,25) {
      freq[i] = query( x, y, i );
      //~ cerr << "F: " << i << " " << freq[i] << '\n';
      update( x, y, 0, i ); // clear range for c        
    }
    
    ll cur = x;
    
    if( k == 1 ) { // ASC
      FOR(i,0,25) {
        if( freq[i] == 0 ) continue;
        update( cur, cur+freq[i]-1, 1, i );
        cur += freq[i];
      }
    }
    else { // DSC
      ROF(i,25,0) {
        if( freq[i] == 0 ) continue;
        update( cur, cur+freq[i]-1, 1, i );
        cur += freq[i];
      }
    }
    
  }
  
  FOR(i,0,25) get( 1, n, i );
  FOR(i,1,n) cout << s[i];
}
