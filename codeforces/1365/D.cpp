#include <bits/stdc++.h>
typedef long long ll;
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

ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0,  0, -1, 1};

ll n, m;
char maze[55][55] = {0};
bool explr[55][55] = {0};

void dfs(ll x, ll y) {
  if (x < 1 || x > n || y < 1 || y > m) return;
  else if (maze[x][y] == '#') return;
  else if (explr[x][y]) return;
  explr[x][y] = true;

  FOR(k,0,3) {
    ll nx = x + dx[k], ny = y + dy[k];
    dfs(nx, ny);
  }
}

int main() {
  ll t; cin >> t;
  while (t--) {
    FOR(i,0,54) FOR(j,0,54) {
      maze[i][j] = ' ';
      explr[i][j] = 0;
    }
    cin >> n >> m;
    
    ll good = 0;
    FOR(i,1,n) FOR(j,1,m) {
      cin >> maze[i][j];
      if(maze[i][j] == 'G') good++;
    }
    
    FOR(i,1,n) FOR(j,1,m) if (maze[i][j] == 'B') {
      FOR(k,0,3) {
        ll nx = i + dx[k], ny = j + dy[k];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if (maze[nx][ny] == '.') maze[nx][ny] = '#';
      }
    }
  
    dfs(n, m);

/*
    FOR(i,1,n) {
      FOR(j,1,m) cerr << explr[i][j];
      cerr << endl;
    }
*/
    ll gc = 0, bc = 0;
    FOR(i,1,n) FOR(j,1,m) {
      if (maze[i][j] == 'G' && explr[i][j]) gc++;
      else if (maze[i][j] == 'B' && explr[i][j]) bc++;
    }

    //cerr << bc << " " << gc << " = " << good << '\n';
    if (bc > 0 || gc != good) cout << "No\n";
    else cout << "Yes\n";
  }
}
