#include <bits/stdc++.h>
typedef int ll;
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( auto it = v.begin(); it != v.last(); it++ )
#define all(c) (c).begin(), (c).last()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl;
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll L[500005], R[500005];
bool C[500005];
ll start[500005], last[500005];

ll nextRight( ll x ) {
  if( !C[x] || R[x] == x+1 )
    return R[x];
  return R[x] = nextRight( R[x] );
}

ll nextLeft( ll x ) {
  if( !C[x] || L[x] == x-1 )
    return L[x];
  return L[x] = nextLeft( L[x] );
}

int main() {
  ll n, m, p;
  cin >> n >> m >> p;
  
  string s; cin >> s;
  s = " " + s;
  
  stack<int> st;
  
  FOR(i,1,n)
    if( s[i] == ')' ) {
      ll p = st.top();
      st.pop();
      start[p] = start[i] = p;
      last[p] = last[i] = i;
      
      //~ cerr << "R: " << i << ' ' << p << " " << i << '\n';
    }
    else
      st.push(i);
  
  FOR(i,0,n)
    L[i] = i-1, R[i] = i+1;
  
  
  string Q; cin >> Q;
  ll ptr = p;
  
  for( char q : Q ) {
    if( q == 'R' )
      ptr = nextRight(ptr);
    else if( q == 'L' )
      ptr = nextLeft(ptr);
    else if( q == 'D' ) {
      ll r = nextRight( last[ptr] );
      ll l = nextLeft( start[ptr] );
      
      C[ start[ptr] ] = C[ last[ptr] ] = 1;
      
      L[r] = l; R[l] = r; 
      
      ptr = r;
      if( ptr == n+1 )
        ptr = l;
    }
    
    //~ debug(ptr);
  }
  
  ptr = nextRight(0);
  while( ptr <= n ) {
    cout << s[ptr];
    ptr = nextRight(ptr);
  }
    
}
