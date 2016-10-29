#include <bits/stdc++.h>
typedef long long ll;
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

ll tree[3][1000005];
ll MaxVal;


void update( ll x, ll t, ll val ) {
  while( x <= MaxVal ) {
    tree[t][x] += val;
    x += (x&-x);
  }
}

ll read( ll x, ll t ) {
  ll sum = 0;
  while(x) {
    sum += tree[t][x];
    x -= (x&-x);
  }
  return sum;
}

int main() {
  BOOST;
  ll n; cin >> n;
  set<ll> arr;
  
  vector<ll> v(n+1);
  
  FOR(i,1,n) {
    cin >> v[i];
    arr.insert( v[i] );
  }
  
  map<ll,ll> hash;
  ll cnt = 0;
  for( ll x : arr ) hash[x] = ++cnt;
  MaxVal = cnt;
  
  ll ans = 0;
  
  ROF(i,n,1) {
    ll x = hash[v[i]];
    ans += read( x-1, 2 );
    ll two = read( x-1, 1 );
    update( x, 1, +1 );
    update( x, 2, two );
  }
  
  cout << ans;
}
