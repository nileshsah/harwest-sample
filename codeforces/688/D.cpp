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

ll prime[1000005], lcm[1000005];
ll N = 1000000;

int main() {
  BOOST;
  
  ll n, k;
  cin >> n >> k;
  
  FOR(i,2,N)
    if( !prime[i] ) {
      for( ll j = i; j <= N; j += i )
        prime[j] = i;
    }
    
  FOR(i,1,n) {
    ll x; cin >> x;
    
    while(x>1) {
      ll p = prime[x], count = 0 ;
      while( x%p == 0 ) {
        x /= p;
        count++;
      }
      lcm[p] = max( lcm[p], count );
    }
    
  }
  
  while(k>1) {
    ll p = prime[k], count = 0;
    while( k%p == 0 ) {
      k /= p;
      count++;
    }
    if( count > lcm[p] ) {
      cout << "No";
      return 0;
    }
  }
  
  cout << "Yes";
  
}
