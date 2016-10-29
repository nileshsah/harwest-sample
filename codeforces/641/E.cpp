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

struct pairhash {
public:
  template <typename T, typename U>
  size_t operator()(const pair<T, U> &x) const
  {
    return hash<T>()(x.first) ^ hash<U>()(x.second);
  }
};

ll MaxVal = 100000;
unordered_map< pair<ll,ll>, ll, pairhash > tree;

void update( ll x, ll t, ll val ) {
  while( t <= MaxVal ) {
    tree[{x,t}] += val;
    t += (t&-t);
  }
}

ll read( ll x, ll t ) {
  ll sum = 0;
  while(t>0) {
    sum += tree[{x,t}];
    t -= (t&-t);
  }
  return sum;
}

int main() {
  BOOST;
  unordered_map<ll,ll> hash;
  vector< pair< pair<ll,ll>, pair<ll,ll> > > Q;
  
  set<ll> Tarr;
  
  ll n; cin >> n;
  FOR(i,1,n) {
    ll a, t, x;
    cin >> a >> t >> x;
    Q.pb( { { t, i }, { a, x } } );
    Tarr.insert(t);
  }
  
  ll cnt = 0;
  for( ll x : Tarr ) hash[x] = ++cnt;
  MaxVal = cnt;
  
  for( auto q : Q ) {
    ll x = q.S.S, op = q.S.F, t = q.F.F;
    
    if( op == 1 ) {
      update( x, hash[t], +1 );
    }
    else if( op == 2 ) {
      update( x, hash[t], -1 );
    }
    else if( op == 3 )
      cout << read( x, hash[t] )  << '\n';
  }
  
}
