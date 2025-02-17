#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back

int memo[1000] = {100000};

int supw(int arr[], int i, int n) {
    // cout<<i<<endl;
    if (i == n) {
        return min(min(memo[i-1],memo[i-2]),memo[i-3]);
    }
    memo[i] = min(min(memo[i-1],memo[i-2]),memo[i-3]) + arr[i];

    return supw(arr, i+1, n);
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0;i<n;i++) {
        int t;
        cin >>t;
        arr[i] = t;
    }
    memo[0] = arr[0];
    memo[1] = arr[1];
    memo[2] = arr[2];
    int supwResult = supw(arr, 0, n);
    int sum = 0;
    for(int i = 0;i<n;i++) {
        sum+=arr[i];
    }
    cout <<sum - supwResult ;
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