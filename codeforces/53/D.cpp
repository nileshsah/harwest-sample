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
	int n; cin >> n;
	vector<ll> a(n), b(n);
	
	FOR(i,0,n-1) cin >> b[i];
	FOR(i,0,n-1) cin >> a[i];
	
	vector< pair<ll,ll> > v;
	
	int ptr = 0;
	while( ptr < n ) {
		int q = ptr;
		while( a[q] != b[ptr] ) q++;
		ROF(i,q,ptr+1) {
			v.pb( {i-1,i} );
			swap( a[i-1], a[i] );
		}	
		ptr++;
	}
	
	cout << v.size() << '\n';
	for( auto p : v ) 
		cout << p.F+1 << ' ' << p.S+1 << '\n';
}
