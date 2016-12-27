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

const ll MAXN = 10000001;
ll a[1000005];
ll cnt[MAXN];
ll sub[MAXN];


int main() {
  BOOST;
  ll n, k;
  cin >> n >> k;
  
  FOR(i,1,n) {
    cin >> a[i];
    cnt[ a[i] ] += 1;
  }
    
  ll cur = 0;
  
  ROF(i,MAXN-1,1) {
    cur += cnt[i];
    cur -= sub[i];
    
    cnt[i/2] += cnt[i];
    cnt[(i+1)/2] += cnt[i];
    sub[(i+1)/2] += cnt[i];
    
    if( cur >= k ) {
      cout << i;
      return 0;
    }
  }
    
  cout << -1;
}
