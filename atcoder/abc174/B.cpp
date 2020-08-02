#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    long long n;

    cin >> n;

    long long m;

    cin >> m;

    long long res=0;

    for(long long i = 0 ; i < n ; i++) {

        long long x;

        cin >> x;

        long long y;

        cin >> y;

        long double dis = sqrtl(x*x + y*y) ;

        if(dis<=m) {

            res++;

        }

    }

    cout << res << '\n';

    return 0;

}

