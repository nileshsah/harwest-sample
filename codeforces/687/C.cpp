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

ll v[505];

bool dp[501][501][501];
bool visit[501][501][501];

bool rec( ll x, ll sub, ll sum ) {
  
  if( x == 0 && sub == 0 && sum == 0 )
    return 1;
  if( x <= 0 || sub > sum ) 
    return 0;
  
  if( visit[x][sub][sum] )
    return dp[x][sub][sum];
  
  bool ret = 0;
  
  if( sub-v[x] >= 0 && sum-v[x] >= 0 )
    ret |= rec( x-1, sub-v[x], sum-v[x] );
  if( !ret && sum-v[x] >= 0 )
    ret |= rec( x-1, sub, sum-v[x] );
  if( !ret )
    ret |= rec( x-1, sub, sum );
  
  
  visit[x][sub][sum] = 1;
  return dp[x][sub][sum] = ret;
}

int main() {
  BOOST;
  
  ll n, k;
  cin >> n >> k;
  
  FOR(i,1,n) cin >> v[i];
  
  vector<ll> ans;
    
  FOR(i,0,k)
    if( rec( n, i, k ) )
      ans.pb(i);
  
  cout << ans.size() << '\n';
  for( ll x : ans ) cout << x << ' ';    
}
