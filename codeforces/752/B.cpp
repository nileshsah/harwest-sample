#include <bits/stdc++.h>
typedef long long ll;
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
using namespace std;

int main() {
  set<char> v[256];
  string s, t;
  cin >> s >> t;
  
  FOR(i,0,s.size()-1) {
    v[ (int)s[i] ].insert( t[i] );
    v[ (int)t[i] ].insert( s[i] );
  }
  
  ll c = 0;
  
  FOR(i,'a','z') {
    if( !v[i].empty() && v[i].size() > 1 ) {
      cout << -1;
      return 0;
    }
    
    if( !v[i].empty() ) {
      ll l = *v[i].begin();
      if( !v[l].empty() && *v[l].begin() != i ) {
        cout << -1;
        return 0;
      }
      c++;
    }
    
  }
  
  vector< pair<char,char> > idx;
  set<char> pr;
  FOR(i,'a','z') {
    if( v[i].empty() ) continue;
    if( pr.count(i) || pr.count((*v[i].begin())) ) continue;
    if( (char)i == *v[i].begin() ) continue;
    idx.pb( { (char)i ,(*v[i].begin()) } );;
    pr.insert(i); pr.insert((*v[i].begin()));
  }
  
  cout << idx.size() << '\n';
  for( auto p : idx )
    cout << p.F << ' ' << p.S << '\n';
  
  
}
