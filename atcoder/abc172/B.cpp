
/*

    This Code and Template is my personal property,
    It's handcrafted by me (Siddharth Singh)

    You are not allowed to lift Macros/Functions or any thing
    without my permission.

    If you want to take any thing, let me know first.
    If i approve then only you can use it.

    I will mention everyone who copies without my permission

    List of uncreative/non-talented people copying macros/template
    
    ~ Updated 2nd June 2020

    1. 
    2. 
*/

#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar



// Type Redefinitions
#define int long long
#define double long double
#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define ADJ map<int,set<int>>
#define vpii vector<pii>
#define fmap gp_hash_table
#define LONG LLONG

// Shorthand Macros
#define pb push_back
#define ed end()
#define bg begin()
#define sz size()
#define ln length()
#define all(x) x.begin(),x.end()
#define endl "\n"
#define NL cout<<'\n';
#define F first
#define S second
#define disp(x) for(auto t : x )cout<<t<<" ";
#define for0(n) for(int i=0;i<n;i++)
#define for0j(n) for(int j=0;j<n;j++)
#define oldfor(v) for(auto it = v.begin(); it != v.end(); ++it)
#define SS <<" "<<
#define acum accumulate
#define arrin(a,n) vi a(n);for0(n){cin>>a[i];}
#define pf(x) cout<<x<<endl;
#define Check pf("Check")
#define gridin(num,n,m) for0(n){for0j(m) cin>>num[i][j];}
#define dispgrid(num,n,m) for0(n){for0j(m) cout<<num[i][j]<<" "; cout<<endl;}

// IO Helpers
#define tks(x) string x;cin >> x;
#define tk(a) int a;cin>>a;
#define tk2(a,b)tk(a)tk(b)
#define tk3(a,b,c)tk2(a,b)tk(c)
#define tk4(a,b,c,d)tk2(a,b)tk2(c,d)
#define tk5(a,b,c,d,e)tk4(a,b,c,d)tk(e)
#define tk6(a,b,c,d,e,f)tk3(a,b,c)tk3(d,e,f)
#define tk7(a,b,c,d,e,f,g)tk6(a,b,c,d,e,f)tk(g)
#define tk8(a,b,c,d,e,f,g,h)tk7(a,b,c,d,e,f,g)tk(h)
#define addEdge(adj) tk2(u,v) adj[u].insert(v);adj[v].insert(u);
#define test tk(test)while(test--)

// Common Affirmations
#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;


// Common Constants
const int MOD=1000000007;
const int N=100000;
#define accuracy chrono::steady_clock::now().time_since_epoch().count()

// Overloaded Ostream Classes
template < typename T >
ostream &operator<<(ostream &os,const vector<T> &v){os<< "{";oldfor(v){if(it!=v.bg)os<<", ";os<<*it;}return os << "}";}

template<typename F, typename S>
ostream& operator<<(ostream& os,const pair<F,S> &p){return os << "(" << p.F << ", " << p.S << ")";}

template < typename T >
ostream &operator << (ostream &os, const set<T> &v){os << "[";oldfor(v){if(it!=v.bg)os<< ", ";os << *it;}return os << "]";}

template < typename T >
ostream &operator << (ostream &os, const multiset<T> &v){os << "[";oldfor(v){if(it!=v.bg) os << ", ";os<<*it;}return os << "]";}

template < typename F, typename S >
ostream &operator <<(ostream & os, const map<F,S> &v){os << "[";oldfor(v){if(it!=v.bg)os<< ", ";os<< it->F<<" = "<<it->S;}return os << "]";}



/*
    Common Theory : 
    

    1. To find number of elements less than k in array a
       answer would be int res = upper_bound(all(a),k) - a.bg

    2. To find number of elements greater than k in array a
       answer would be int res = a.ed - upper_bound(all(a),k)

    3. Min Heap = priority_queue<int,vector<int>, greater<int>> que;
       Max Heap = priority_queue<int> que;

    4. Is Function Monotonus, Can you solve for a given res?
       Think about Binary Searching !

    5. Can't be sure if greedy is optimal? Constraints are low?
       Think about Dynamic Programming !

    6. Don't forget a grid is a graph.

    7. Watch out for function overhead

    8. Confused ? Think against these algos

       1. Prefix,Suffix
       2. Difference Array
       3. Nx32 Bit Frame
       4. DP ~ Can you create a state transition from dp[i][j] to dp[i-1][j] or dp[i][j+1]
       5. Sliding Window
       6. Hashing

    9. Guess from Solution's Expected Time Complexity

    10. Sometimes it's easy to solve the complement of a problem.

    11. If the constraints go up to 10^18, there can only be two solution
        1. Solve it in Log(n)
        2. Solution for bigger values is a constant

*/

void slow(){

}

void fast(){

}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    slow();
    fast();
    string a;
    cin >> a;
    string b;
    cin >> b;
    multiset<char> ms(all(a));
    int res=0;
    for0(b.ln){
    	if(b[i]!=a[i])res++;
    }
    pf(res)
    return 0;
}