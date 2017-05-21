#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD ((ll)(1e9)+7);

int main() {
	string s; 
	cin >> s;
	
	ll cur = 0, ans = 0;
	for (int i = s.size()-1; i >= 0; i--) {
		if (s[i] == 'a') {
			ans = ( ans + cur )%MOD;
			cur = ( cur * 2 )%MOD;
		}
		else if (s[i] == 'b') {
			cur = (cur + 1)%MOD;
		}
	}
	cout << ans;
}