#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

double EPS = 1e-12;

int main() {
  double x, y, z;
  cin >> x >> y >> z;
    
  long double a[13]; string s[13];
      
  a[1] = powl(y,z)*log(x);
  a[2] = powl(z,y)*log(x);
  a[3] = y*z*log(x);
  a[4] = y*z*log(x);

  a[5] = powl(x,z)*log(y);
  a[6] = powl(z,x)*log(y);
  a[7] = x*z*log(y);
  a[8] = x*z*log(y);

  a[9]  = powl(x,y)*log(z);
  a[10] = powl(y,x)*log(z);
  a[11] = x*y*log(z);
  a[12] = x*y*log(z);

  
  s[1] = "x^y^z";
  s[2] = "x^z^y";
  s[3] = "(x^y)^z";
  s[4] = "(x^z)^y";
  
  s[5] = "y^x^z";
  s[6] = "y^z^x";
  s[7] = "(y^x)^z";
  s[8] = "(y^z)^x";
  
  s[9]  = "z^x^y";
  s[10] = "z^y^x";
  s[11] = "(z^x)^y";
  s[12] = "(z^y)^x";
  
  
  long double mx = LONG_MIN;
  
  FOR(i,1,12) {
    debug(s[i]); debug(a[i]);
    mx = max( mx, a[i] );
  }
  
  FOR(i,1,12) 
    if( fabs( mx - a[i] ) < EPS ) {
       cout << s[i]; 
       return 0;
  }
}
