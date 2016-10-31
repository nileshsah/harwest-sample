#include <bits/stdc++.h>
typedef int ll;
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
  string s; cin >> s;
  bool v[256] = {0};
  v['A'] = v['E'] = v['I'] = v['O'] = v['U'] = v['Y'] = 1;
  
  ll last = -1, maxDist = 0;
  FOR(i,0,s.size()-1) {
    if( v[ (int)s[i] ] ) {
      maxDist = max( maxDist, i-last );
      last = i;
    }
  }
  
  maxDist = max( maxDist, (int)s.size()-last );
  
  cout << maxDist;
}
