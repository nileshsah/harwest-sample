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

const bool SYN = 0;
const bool ANT = 1;

ll same[100005], opp[100005];

int find(int x) {
	if( x == 0 ) return 0;
	if( same[x] == x )
		return x;
	return same[x] = find(same[x]);
}

void join(int x, int y) {
	if( x == 0 || y == 0 )
		return;
	ll p = find(x);
	ll q = find(y);
	
	if( p == q )
		return;
	same[p] = q;
}

int main() {
	ll n, m, q;
	cin >> n >> m >> q;
	
	map<string,int> val;
	
	FOR(i,1,n) {
		string s; cin >> s;
		val[s] = i;
		same[i] = i;
	}
	
	FOR(i,1,m) {
		int c; string a, b;
		cin >> c >> a >> b;
		
		ll p = find(val[a]);
		ll q = find(val[b]);
		
		opp[p] = find( opp[p] );
		opp[q] = find( opp[q] );
				
		if( c == 1 ) {
			if( opp[p] == q )
				cout << "NO\n";
			else {
				cout << "YES\n";
				join(p,q);
				join(opp[p],opp[q]);
				ll u = find(p), v;
				
				if( opp[p] != 0 && opp[q] != 0 )
					v = find( opp[p] );
				else if( opp[p] != 0 )
					v = find( opp[p] );
				else if( opp[q] != 0 )
					v = find( opp[q] );
				else
					continue;
				opp[u] = v, opp[v] = u;
			}
		}
		else {
			if( p == q )
				cout << "NO\n";
			else {
				join(q,opp[p]);
				join(p,opp[q]);
				opp[q] = find(p);
				opp[p] = find(q);
				cout << "YES\n";
			}
		}
	}
	
	FOR(i,1,q) {
		string a, b;
		cin >> a >> b;
		
		ll p = find(val[a]);
		ll q = find(val[b]);
		
		opp[p] = find( opp[p] );
		opp[q] = find( opp[q] );
		
		if( p == q )
			cout << "1\n";
		else if( opp[p] == q || opp[q] == p )
			cout << "2\n";
		else
			cout << "3\n";
	}
}
