#include <bits/stdc++.h>
typedef int ll;
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
#define sz(a) (int)a.size()
using namespace std;

int main() {
	BOOST;
	ll n, m, k;
	cin >> n >> m >> k;
	
	vector<ll> has;
	vector< pair<ll,ll> > shop;
	vector<ll> v(m+1);
	
	int cur = 0;
	
	FOR(i,1,n) {
		ll x; cin >> x;
		has.pb(x);
	}
	
	FOR(i,1,m) {
		ll x; cin >> x;
		shop.pb({x,i});
	}
	
	sort( all(has) );
	sort( all(shop) );
	
	ll ans = 0, hptr = 0, sptr = 0;
	
	while( hptr < sz(has) || sptr < sz(shop) ) {
		int got = 0;
		while( hptr < sz(has) && has[hptr] == cur ) {
			hptr++;
			got++;
		}
		if( got > k ) {
			ll diff = got-k;
			if( ans < diff ) {
				cout << "-1";
				return 0;
			}
			ans -= diff;
			got -= diff;
		}
		while( sptr < sz(shop) && shop[sptr].F < cur )
			sptr++;
		while( sptr < sz(shop) && got < k ) {
			v[ans] = (shop[sptr].S);
			sptr++;
			got++; ans++;
		}
		while( hptr < sz(has) && got < k ) {
			hptr++;
			got++;
		}
		cur++;
	}
	
	cout << ans << '\n';
	FOR(i,0,ans-1) cout << v[i] << ' ';
}