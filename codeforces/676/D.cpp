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

// 3 2 1 0
// U R D L

ll INF = INT_MAX/100;

bitset<4> arr[1005][1005];
ll D[1005][1005][4];

void rotate( bitset<4>& b ) {
  bool lsb = b[0];
  b = b>>1;
  if(lsb) b.set(3);
}

bool go( bitset<4> x, bitset<4> y, ll r, char c ) {
  r  = r%4;
  FOR(i,1,r) {
    rotate(x);
    rotate(y);
  }
  
  //~ cerr << "GO: " << x << ' ' << y << ' ' << r << ' ' << c << '\n';
  
  if( c == 'R' ) 
    return (x[2]&y[0]);
  else if( c == 'L' )
    return (x[0]&y[2]);
  else if( c == 'U' )
    return (x[3]&y[1]);
  else if( c == 'D' )
    return (x[1]&y[3]);
  
  return 0;
}

ll dx[] = { 0, 0, 1, -1 };
ll dy[] = { 1, -1, 0, 0 };
char dir[] = { 'R', 'L', 'D', 'U' };

int main() {
  BOOST;
  ll n, m;
  cin >> n >> m;
  
  FOR(i,0,n+1) FOR(j,0,m+1) arr[i][j] = bitset<4>("0000");
  
  FOR(i,1,n)
    FOR(j,1,m) {
      char c; cin >> c;
      
      // U R D L
      if( c == '+' )
        arr[i][j] = bitset<4>("1111");
      if( c == '-' )
        arr[i][j] = bitset<4>("0101");
      if( c == '|' )
        arr[i][j] = bitset<4>("1010");
      if( c == '^' )
        arr[i][j] = bitset<4>("1000");
      if( c == '<' )
        arr[i][j] = bitset<4>("0001");
      if( c == '>' )
        arr[i][j] = bitset<4>("0100");
      if( c == 'v' )
        arr[i][j] = bitset<4>("0010");
      if( c == 'L' )
        arr[i][j] = bitset<4>("1110");
      if( c == 'R' )
        arr[i][j] = bitset<4>("1011");
      if( c == 'U' )
        arr[i][j] = bitset<4>("0111");
      if( c == 'D' )
        arr[i][j] = bitset<4>("1101");
      if( c == '*' )
        arr[i][j] = bitset<4>("0000");
    
    }
    
  ll xt, yt, xm, ym;
  cin >> xt >> yt >> xm >> ym;
  
  FOR(i,0,n+1) FOR(j,0,m+1) FOR(k,0,3) D[i][j][k] = INF;
  
  set< pair< pair<ll,ll>, pair<ll,ll>  > > idx;
  
  idx.insert( { {0,0}, {xt,yt} } );
  D[xt][yt][0] = 0;
  
  while(!idx.empty()) {
    auto top = *idx.begin();
    idx.erase(idx.begin());
    
    ll x = top.S.F, y = top.S.S;
    ll t = top.F.F, r = top.F.S;
    
    //~ cerr << "R: " << x << ' ' << y << " [" << t << ", " << r << "]\n";
    
    FOR(k,0,3) {
      
      if( D[x][y][(r+k)%4] > t+k ) {
        idx.erase( { { D[x][y][(r+k)%4], (r+k)%4 }, {x,y} } );
        D[x][y][(r+k)%4] = t+k;
        idx.insert( { { D[x][y][(r+k)%4], (r+k)%4 }, {x,y} } );
      }
 
      
      FOR(i,0,3) {
        ll R = ( r + k )%4, T = t+k+1;
 
        ll xx = x + dx[i];
        ll yy = y + dy[i];
         
        if( D[xx][yy][R] > T && go( arr[x][y], arr[xx][yy], R, dir[i] ) ) {
          idx.erase( { { D[xx][yy][R], R }, { xx, yy } } );
          D[xx][yy][R] = T;
          idx.insert( { { D[xx][yy][R], R }, { xx, yy } } );
          //~ cerr << "IN: " << xx << ' ' << yy << " [" << T << ", " << R << "]\n";
        }
      }
    }
    
  }
  
  ll ans = INF;
  FOR(i,0,3)
    ans = min( ans, D[xm][ym][i] );
  
  if( ans == INF ) ans = -1;
  
  cout << ans;
}
