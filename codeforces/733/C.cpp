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

vector< pair<ll,char> > ans;
ll offset = 0;

void solve( vector<ll> &p ) {
  while( p.size() > 1 ) {
    ll ptr = 0, m = 0;
    FOR(i,0,p.size()-1) {
      if( m < p[i] ) 
        m = p[i], ptr = i;
      else if( m == p[i] and ( ( i > 0 && p[i-1] < p[i] ) or ( i < (ll)p.size()-1 && p[i+1] < p[i] ) ) )
        ptr = i;
    }
  
   if( ptr > 0 && p[ptr-1] < p[ptr] ) {
     ans.pb( { offset+ptr, 'L' } );
     p[ptr] += p[ptr-1];
     p.erase( p.begin()+ptr-1 );
   }
   else if( ptr < (int)p.size()-1 && p[ptr+1] < p[ptr] ) {
     ans.pb( { offset+ptr, 'R' } );
     p[ptr] += p[ptr+1];
     p.erase( p.begin()+ptr+1 );
   }
   else {
    cout << "NO";
    exit(0);
   }
  }
}

int main() {
  ll n; cin >> n;
  vector<ll> v(n);
  
  FOR(i,0,n-1) cin >> v[i];
  
  ll k; cin >> k;
  vector<ll> end(k);
  
  FOR(i,0,k-1) cin >> end[i];
    
  while(!v.empty()) {
    
    if( end.empty() ) {
      cout << "NO";
      return 0;
    }
    
    ll make = *end.begin();
    end.erase(end.begin());
    
    ll sum = 0;
    vector<ll> process;
    
    while( sum < make && !v.empty()) {
      sum += *v.begin();
      process.pb(*v.begin());
      v.erase(v.begin());
    }
    
    if( sum != make ) {
      cout << "NO\n";
      return 0;
    }
    
    solve(process);
    offset++;
  }
  
  if( !end.empty() || !v.empty() ) {
    cout << "NO";
    return 0;
  }
  
  cout << "YES\n";
  for( auto p : ans )
    cout << p.F+1 << ' ' << p.S << '\n';
}
