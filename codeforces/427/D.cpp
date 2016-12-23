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

int lcp[5001][5001];

void LCP( string &a, string &b ) {
  ROF(i,a.size()-1,0)
    ROF(j,b.size()-1,0)
      if( a[i] == b[j] )
        lcp[i][j] = 1 + lcp[i+1][j+1];
      else
        lcp[i][j] = 0;
}

int main() {
  BOOST;
  string a, b;
  cin >> a >> b;
    
  int lenA[5005] = {0};
  int lenB[5005] = {0};
  
  memset( lcp, 0, sizeof lcp );
  LCP(a,a);
  
  FOR(i,0,a.size()-1)
    FOR(j,0,a.size()-1)
      if( i != j )
        lenA[i] = max( lenA[i], lcp[i][j] );
  
  memset( lcp, 0, sizeof lcp );
  LCP(b,b);
  
  FOR(i,0,b.size()-1)
    FOR(j,0,b.size()-1)
      if( i != j )
        lenB[i] = max( lenB[i], lcp[i][j] );
        
  memset( lcp, 0, sizeof lcp );
  LCP(a,b);
  int ans = INT_MAX;
  
  FOR(i,0,a.size()-1)
    FOR(j,0,b.size()-1)
      if( lenA[i] < lcp[i][j] && lenB[j] < lcp[i][j] )
        ans = min( ans, max(lenA[i],lenB[j])+1 );
  
  if( ans == INT_MAX ) ans = -1;
  cout << ans;
}
