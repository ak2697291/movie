#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back

int memo[1000];

int maxPrice(int n,int prices[]) {
    if (n == 0) {
        return 0;
    }
    if (memo[n] != -1) {

        return memo[n];
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans = max(ans, prices[i]+ maxPrice(n-i, prices));
        

    }
    return memo[n] = ans;
}

void solve() {
    int n;
    cin >>n;
    int prices[n+1];
    for (int i=1;i<=n;i++) {
        int t;
        cin>>t;
        prices[i] = t;
    }
    memset(memo, -1, sizeof(memo));
    cout << maxPrice(n, prices)<<endl;
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