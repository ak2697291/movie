#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back
int minStep = 1000;
int memo[100000];
int findMinStep(int n, int steps) {
    if (n == 1) {
        return steps;
    }
    if (n < 1) {
        return INT_MAX;
    }

    int &ans = memo[n];
    if (ans != -1) return ans;
    ans = INT_MAX;

    if (n % 3 ==0) {
        ans =  min (ans, findMinStep(n/3, steps+1));
    }
    if (n % 2 == 0) {
        ans =  min(ans, findMinStep(n/2, steps+1));
    }

    ans =  min(ans, findMinStep(n -1, steps+1));

    return ans;
    
}
void solve() {
    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout<<findMinStep(n, 0);
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