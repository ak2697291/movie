#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back

void solve() {
    int n;
    cin >> n;
    int dp[n+1];
    dp[0]  = 0;
    for(int i = 1; i<=n; i++) {
        dp [i] = dp[i/2] + i%2;
        cout<<i<<"->"<<dp[i]<<endl;
    }
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