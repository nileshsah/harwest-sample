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

ll num( string s ) {
  ll val = 0;
  while( !s.empty() ) {
    val *= 10;
    val += *s.begin() - '0';
    s.erase(s.begin());
  }
  return val;
}

int main() {
  ll n, m; cin >> n >> m;
  vector< pair<ll,char> > t, s, T, S, idx;
  
  FOR(i,1,n) {
    string str, val; cin >> str;
    char c = str.back();
    str.pop_back(); str.pop_back();
    
    t.pb( { num(str), c } );
  }
  
  FOR(i,1,m) {
    string str, val; cin >> str;
    char c = str.back();
    str.pop_back(); str.pop_back();
    
    s.pb( { num(str), c } );
  }
  
  auto begin = t[0];
  FOR(i,1,n-1) {
    if( begin.S == t[i].S )
      begin.F += t[i].F;
    else {
      T.pb(begin);
      begin = t[i];
    }
  } 
  T.pb(begin);
  
  // #loser 
  
  begin = s[0];
  FOR(i,1,m-1) {
    if( begin.S == s[i].S )
      begin.F += s[i].F;
    else {
      S.pb(begin);
      begin = s[i];
    }
  } 
  S.pb(begin);
  
  ll ans = 0;
  
  if( S.size() == 1 ) {
    for( auto p : T )
      if( p.S == S[0].S && p.F >= S[0].F )
        ans += p.F - S[0].F + 1;
    cout << ans;
    return 0;   
  }
  
  FOR(i,1,S.size()-2)
    idx.pb(S[i]);
  idx.pb( { 0, 0 } );
  FOR(i,0,T.size()-1)
    idx.pb(T[i]);
  
  vector<ll> z(idx.size(),0);
  ll sz = S.size()-2, len = idx.size();

  int L = 0, R = 0;
  for (int i = 1; i < len; i++) {
    if (i > R) {
      L = R = i;
      while (R < len && idx[R-L] == idx[R]) R++;
      z[i] = R-L; R--;
    } else {
      int k = i-L;
      if (z[k] < R-i+1) z[i] = z[k];
      else {
        L = i;
        while (R < len && idx[R-L] == idx[R]) R++;
        z[i] = R-L; R--;
      }
    }
    
    //~ cerr << "R: " << i << " " << L << ' ' << R << " = " << z[i] << '\n';
  }
  
  FOR(i,sz+1,idx.size()-1) {
    //~ debug(z[i]);
    if( z[i] == sz ) {
      bool exp = idx[i-1].S == S[0].S && idx[i-1].F >= S[0].F;
      if( i+sz >= (int)idx.size() ) continue;
      exp &= idx[i+sz].S == S.back().S && idx[i+sz].F >= S.back().F;
      if( exp ) ans += 1;
    }
  }
    
  cout << ans;  
}
