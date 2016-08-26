#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define eb emplace_back
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl;
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
    ll x; cin >> x;
    vector< pair<ll,ll> > v;
    
    FOR(i,1,1500000) {
        ll inc = (i*(i+1))/2;
        ll start = ( i*(i+1)*(2*i+1) )/6;
        
        if( x - start < 0 ) break;
        if( ( x - start )%inc != 0 ) continue;
        
        ll n = ( x - start )/inc + i;
        v.pb( mp( min(i,n), max(i,n) ) );
        if( i != n )
        v.pb( mp( max(i,n), min(i,n) ) );
    }
    
    sort( all(v) );
    
    cout << v.size() << '\n';
    for( auto p : v )
     cout << p.F << ' ' << p.S << '\n';
    
}