#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back

vector<int> memo;
int cnt = 0;
int fib(int n) {

    cnt++;

    if (n<=2) {
        return 1;
    }
    if (memo[n] !=-1) {
        return memo[n];
    }

    int result = fib(n-1) + fib(n-2);

    memo[n] = result;
    return result;


}
void solve() {
    int n;
    cin >>n;
    memo.resize(n+1, -1);
    cout<<fib(n)<<endl;
    cout<<cnt;
}
int32_t main() {
#ifndef ONLINE_JUDG
freopen("output.txt","w",stdout);
freopen("input.txt","r",stdin);
#endif
int t= 1;
while(t--) {
solve();
}
return 0;
}