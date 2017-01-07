#include <bits/stdc++.h>
typedef long long ll;
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

const ll INF = LLONG_MAX/100LL;

ll tree[600005], MaxVal;
map<ll,ll> h, revh;

void update( ll x, ll val ) {
  while( x <= MaxVal ) {
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
  ll n, k;
  cin >> n >> k;
  
  multiset< pair<ll,ll> > idx;
  vector<pair<ll,ll>> p(n+1);
  
  set<ll> st;
  
  FOR(i,1,n) {
    ll x, y;
    cin >> x >> y;
    p[i] = {x,y};
    idx.insert( { x, -INF } );
    idx.insert( { y, x } );
    st.insert(x); st.insert(y);
  }
  
  for( ll x : st ) {
    h[x] = ++MaxVal;
    revh[MaxVal] = x;
  }
  
  ll ans = 0, l = 0, r = -1;
  
  while(!idx.empty()) {
    auto top = *idx.begin();
    idx.erase(idx.begin());
    
    ll pt = top.F;
    ll act = top.S;
    
    if( act == -INF )
      update(h[pt],+1);
    else {
      ll start = h[act], end = h[pt];
      while( start <= end ) {
        ll mid = ( start + end )/2;
        if( read(mid) >= k )
          end = mid-1;
        else
          start = mid+1;
      }
      if( read(start) >= k && ans < pt-revh[start]+1 ) {
        l = revh[start], r = pt;
        ans = r-l+1;
      }
      update(h[act],-1);
    }
  }
  
  cout << ans << '\n';
  if( ans == 0 ) {
    FOR(i,1,k) cout << i << ' ';
    return 0;
  }
  FOR(id,1,n) {
    if( k == 0 ) break;
    if( p[id].F <= l && p[id].S >= r ) {
      cout << id << ' ';
      k--;
    }
  }
}
