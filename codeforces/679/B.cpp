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

inline ll cube( ll x ) {
  return x * x * x;
}

int main() {
  ll m; cin >> m;
  
  vector<ll> side;
  ll sum = 0, cur = 1;
  
  while( cur * cur * cur <= m ) {
    if( sum + cube(cur) <= m && sum + cube(cur) < cube(cur+1) ) {
      sum += cube(cur);
      side.pb(cur);
    }
    else
      cur++;
  }
  
  debug(side.size());
  debug(sum);
  
  ROF(i,side.size()-1,0) {
    ll now = side[i];
    ll left = sum - cube(now);
    while( left + cube(now+1) <= m ) {
      ll org = side[i];
      side[i] = now+1;
      bool can = 1; ll pos = 0;
      
      FOR(j,0,side.size()-1) {
        pos += cube(side[j]);
        if( pos > cube(side[j]+1) )
          { can = 0; break; }
      }
    
      side[i] = org;
      
      if(can)
        now++;
      else
        break;
    }
    sum = left + cube(now);
    side[i] = now;
  }
  
  for( ll x : side )
    cerr << x << ' ' ;
  cerr << '\n';
  
  cout << side.size() << ' ' << sum;
}
