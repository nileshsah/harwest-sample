#include <bits/stdc++.h>
typedef long long ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl;
#define F first
#define S second
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll lvl[1000] = {0};

void rec( ll a, ll b, ll c, ll l ) {
  if( b == 2 )
    lvl[l]++;
  if( l > 15 ) return;
  
  rec( b, a, c, l+1 );
  rec( a, c, b, l+1 );
}

ll MOD = (ll)(1e9)+7;

ll modpow( ll x, ll y ) {
  ll ans = 1;
  while(y) {
    if(y&1)
      ans = ( x * ans )%MOD;
    x = ( x * x )%MOD;
    y /= 2;
  }
  return ans;
}

int main() {
  //~ rec( 1, 2, 3, 0 );
  
  //~ FOR(i,1,15)
    //~ cout << lvl[i] << ' ';
  
  ll k; cin >> k;
  ll num = 2, den = 2;
  
  ll res = 1;
  
  FOR(i,1,k) {
    ll a; cin >> a;
    num = modpow( num, a );
    den = modpow( den, a );
    if( a%2 == 0 ) res = 0;
  }
    
  num = ( num * modpow( 2, MOD-2 ) )%MOD;
  if(res) num = ( num - 1 + MOD )%MOD;
  else num = ( num + 1 )%MOD;
  
  num = ( num * modpow( 3, MOD-2 ) )%MOD;
  
  den = ( den * modpow( 2, MOD-2 ) )%MOD;
  
  if( num == 0 ) {
    cout << "0/1";
    return 0;
  } 
  
  cout << num << "/" << den << '\n';
}
