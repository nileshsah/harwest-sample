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

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<ll> v[n+1], a(n+1), val(n+1,0), ans;
	
	FOR(i,1,m) {
	  ll x, y; cin >> x >> y;
	  v[x].pb(y);
	  v[y].pb(x);
	}
	
	set<ll> idx, prc;
	
	FOR(i,1,n) {
	  cin >> a[i];
	  if( a[i] == 0 )
		idx.insert(i);
	}
	
	while(!idx.empty()) {
	  int ptr = *idx.begin();
	  idx.erase(idx.begin());
	  prc.insert(ptr);
	  ans.pb(ptr);
	  
	  for( ll x : v[ptr] ) {
		if( val[x] == a[x] )
		  idx.erase(x);
		val[x]++;
		if( val[x] == a[x] ) {
		  if( prc.count(x) ) {
		    cout << "-1";
		    return 0;
		  }
		  idx.insert(x);
		}
	  }
	}
	
	cout << ans.size() << '\n';
	for( ll x : ans )
	  cout << x << ' ';
}
