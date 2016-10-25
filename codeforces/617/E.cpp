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

// Mo's Algorithm

ll n, m, k;

struct node {
  ll l, r, id;
  bool operator<( const node &a ) const {
    return r < a.r;
  }
};

ll ans = 0;

ll prefix[100005], v[100005], cnt[1<<20];

void add( ll x ) {
  ans += cnt[ (prefix[x]^k) ];
  cnt[ prefix[x] ]++;
  //~ cerr << "ADD: " << x << " " << ans << '\n';
}

void del( ll x ) {
  cnt[ prefix[x] ]--;
  ans -= cnt[ (prefix[x]^k) ];
  //~ cerr << "DEL: " << x << " " << ans << '\n';
}

int main() {
  cin >> n >> m >> k;  

  FOR(i,1,n) cin >> v[i];
  
  ll sq = sqrt(n);
  
  FOR(i,1,n) prefix[i] = ( prefix[i-1]^v[i] );
  
  vector<node> Q[n/sq+1];
  
  FOR(i,1,m) {
    node q; q.id = i;
    cin >> q.l >> q.r;
    q.l--;
    Q[q.l/sq].pb(q);    
  }
  
  ll answer[m+1];
  
  FOR(i,0,n/sq) {
    sort( all(Q[i]) );

    ll left = i*sq, right = i*sq-1;
        
    for( node q : Q[i] ) {
      
      //~ cerr << "Q: " << q.l << ' ' << q.r << '\n';
      
      while( left > q.l ) {
        left--;
        add(left);
      }
      while( left < q.l ) {
        del(left);
        left++;
      }
            
      while( right < q.r ) {
        right++;
        add(right);
      }
      while( right > q.r ) {
        del(right);
        right--;
      }
            
      answer[q.id] = ans;
    }
    FOR(j,left,right)
      del(j);

  }
  
  FOR(i,1,m) cout << answer[i] << '\n';
  
}
