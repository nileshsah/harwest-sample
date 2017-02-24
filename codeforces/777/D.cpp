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
using namespace std;

  
int main() {
  BOOST;
  ll n; cin >> n;
  
  vector<string> v;
  string ans[n];
  
  ll row = 0;
  
  FOR(i,1,n) {
    string s; cin >> s;
    v.pb(s);
    row = max(row,(ll)s.size());
  }
  
  vector<pair<char,ll>> Q[row];
  
  FOR(i,0,n-1) FOR(j,0,v[i].size()-1) {
     Q[j].pb({v[i][j],i});
     if( i+1 < n && j >= (ll)v[i+1].size() )
        Q[j].pb({'^',i+1});
  }
  
  vector<bool> isP(n,1), br(n,0);
    
  FOR(j,0,row-1) {
    stack< pair<char,ll> > st;
    vector<ll> newbr;
    
    for( auto p : Q[j] ) {  
      ll i = p.S; char c = p.F;
      if( isP[i] && !st.empty() && c > st.top().F && !br[i] ) newbr.pb(i);
      
      while( br[i] && !st.empty()) {
        char c = st.top().F;
        int ptr = st.top().S;
              
        if( isP[ptr] && c != '^' ) 
          ans[ptr].pb(c);
        st.pop();
      }
      
      if(!isP[i]) continue;
       
      char top = 0;
      if(!st.empty()) top = st.top().F;
      
      while(!st.empty() && top > c) {
        isP[st.top().S] = 0;
        st.pop();
      }
      st.push({c,i});
    }
    
     while(!st.empty()) {
      char c = st.top().F;
      int ptr = st.top().S;
    
      if( isP[ptr] && c != '^' ) 
        ans[ptr].pb(c);
      st.pop();
    }
    
    for( ll u : newbr ) br[u] = 1;
    
  }
  
  FOR(i,0,n-1) cout << ans[i] << '\n';

}
