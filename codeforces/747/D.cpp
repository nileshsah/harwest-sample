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

ll tree[200005], n;

void update( ll x, ll val ) {
  while( x <= n+1 ) {
    tree[x] += val;
    x += (x&-x);
  }
}

ll read( ll x ) {
  ll sum = 0;
  while(x>0) {
    sum += tree[x];
    x -= (x&-x);
  }
  return sum;
}

int main() {
  ll k;
  cin >> n >> k;
  
  ll need = 0;
  vector<ll> v;
  set<pair<ll,pair<ll,ll>>> idx;
  
  FOR(i,1,n) {
    ll x; cin >> x;
    if( x < 0 ) {
      need++;
      update(i,+1); 
      update(i+1,-1);
      if(!v.empty())
        idx.insert({i-v.back()-1,{v.back()+1,i-1}});
      v.pb(i);
    }
  }
  
  if( need > k ) {
    cout << -1;
    return 0;
  }
  
  ll left = k - need;
  while(!idx.empty() && left>0) {
    ll req = idx.begin()->F;
    ll l = idx.begin()->S.F;
    ll r = idx.begin()->S.S;
    
    if( req > left ) break;
    
    idx.erase(idx.begin());
    left -= req;
    update(l,+1); update(r+1,-1);
  }
  
  bool cur = 0; // summer tyre
  ll ans = 0;
  
  debug(left);
  
  FOR(i,1,n) {
    ll r = read(i);
    if( r > 0 && !cur ) {
      cur = 1;
      ans++;
    }
    else if( r <= 0 && cur ) {
      cur = 0;
      ans++;
    }
    if( !v.empty() && i == v.back() ) {
      if( left >= n-i )
        break;
    }
  }
  
  cout << ans;
}
