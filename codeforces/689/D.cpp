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

template<class TYPE> class SparseTable {
  int N, logN;
  vector< vector<TYPE> > table;
  TYPE ZERO;
  
public:

  SparseTable( int sz, TYPE defVal = 0 ) {
    N = sz;
    logN = log2(N)+1;
    ZERO = defVal;
    table = vector< vector<TYPE> >( N+1, vector<TYPE>(logN+1,defVal) );
  }
  
  void construct( vector<TYPE> v ) {
    assert( (int)v.size() == N );
    
    for( int i = 0; i < N; i++ )
      table[i][0] = v[i];
    
    for( int j = 1; j <= logN; j++ )
      for( int i = 0; i <= N - (1<<j); i++ )
        table[i][j] = F( table[i][j-1], table[i+(1<<(j-1))][j-1] );    
  }
  
  TYPE read( int l, int r ) {
    TYPE ans = ZERO;
    
    for( TYPE j = logN; j >= 0; j-- ) {
      if( l + (1<<j) - 1 <= r ) {
        ans = C( ans, table[l][j] );
        l += (1<<j);
      }
    }
        
    return ans;
  }
  
  virtual TYPE F( TYPE x, TYPE y ) = 0; // Function
  virtual TYPE C( TYPE x, TYPE y ) = 0; // Combine for answer
  
};

class RMQ_MIN : public SparseTable<ll> {

public:

  RMQ_MIN( int sz ) : SparseTable(sz,INT_MAX) {
    cerr << "RMQ_MIN class created..\n";
  }
  
  ll F( ll x, ll y) {
    return min(x,y);
  }
  
  ll C( ll x, ll y ) {
    return min(x,y);
  }
};

class RMQ_MAX : public SparseTable<ll> {

public:

  RMQ_MAX( int sz ) : SparseTable(sz,INT_MIN) {
    cerr << "RMQ_MAX class created..\n";
  }
  
  ll F( ll x, ll y) {
    return max(x,y);
  }
  
  ll C( ll x, ll y ) {
    return max(x,y);
  }
};

int main() {
  BOOST;
  ll n; cin >> n;
  
  vector<ll> a(n), b(n);
  
  FOR(i,0,n-1) cin >> a[i];
  FOR(i,0,n-1) cin >> b[i];
  
  RMQ_MAX MX(n);
  RMQ_MIN MN(n);
  
  MX.construct(a);
  MN.construct(b);

  ll ans = 0;
  
      
  FOR(i,0,n-1) {
    
    ll start = i, end = n-1;
    while( start <= end ) {
      ll mid = ( start + end )/2;
      if( MX.read( i, mid ) - MN.read( i, mid ) >= 0 )
        end = mid-1;
      else
        start = mid+1;
    }
        
    ll lb = start;
      
    if( MX.read( i, lb ) - MN.read( i, lb ) != 0 )
      continue;
    
    start = i, end = n-1;
    while( start <= end ) {
      ll mid = ( start + end )/2;
      if( MX.read( i, mid ) - MN.read( i, mid ) > 0 )
        end = mid-1;
      else
        start = mid+1;
    }
    
    ll ub = end;
    
    ans += ub - lb + 1;
  }
  
  cout << ans;
  
}
