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

int main() {
  BOOST;
  ll n, k;
  cin >> n >> k;
  
  ll a[n+1];
  FOR(i,1,n) cin >> a[i];
  
  ll start = 0, end = 2LL*(1e9);
  while( start <= end ) {
    ll mid = ( start + end )/2;
    ll used = 0;
    FOR(i,1,n)
      used += max(0LL, mid-a[i]);
    if( used < k )
      start = mid+1;
    else
      end = mid-1;
  }
  
  debug(end);
  
  ll used = k;
  
  FOR(i,1,n) {
    used -= max(0LL,end-a[i]);
    a[i] = max( a[i], end );
  }  
  
  FOR(i,1,n)
    if( used && a[i] == end )
      a[i]++, used--;
  
  start = 0, end = 2LL*(1e9);
  while( start <= end ) {
    ll mid = ( start + end )/2;
    ll used = 0;
    FOR(i,1,n) 
      used += max(0LL, a[i]-mid);
    if( used < k )
      end = mid-1;
    else
      start = mid+1;
  }
  
  debug(start);
  end =  start;
  
  used = k;
  FOR(i,1,n) {
    used -= max(0LL, a[i]-end );
    a[i] = min( a[i], end );
  }
  
  FOR(i,1,n)
    if( used > 0 && a[i] == end )
      used--, a[i]--;
  
  
  ll maxVal = INT_MIN, minVal = INT_MAX;
  FOR(i,1,n) {
    maxVal = max( maxVal, a[i] );
    minVal = min( minVal, a[i] );
  }
  
  cout << maxVal - minVal;
}
