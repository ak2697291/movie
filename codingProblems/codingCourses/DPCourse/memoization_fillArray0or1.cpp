#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back

vector<int> memo;

void printArray(int arr[], int n) {
    for (int i=0; i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout <<endl;
}
int func(int n, int arr[], int i) {
    if (i == n) {
        printArray(arr, n);
        return 1;
    }
    if (i == 0){
        arr [i] = 1;
        int a = func(n,arr, i+1);
        arr[i] = 0;
        int b = func(n, arr, i+1);
        return a + b;
    }

    if (arr[i - 1] == 1) {
        arr[i] = 0;
        return func(n, arr, i+1);
    } else {
        arr [i] = 1;
        int a = func(n,arr, i+1);
        arr[i] = 0;
        int b = func(n, arr, i+1);
        return a + b;
    }

}
int func1(int n, int i, bool isOne) {
    if ( i == n+1) {
        return 1;
    }
    int ans = 0;
    
    ans +=func1(n, i+1, false);
    if (!isOne){
        ans +=func1(n, i+1, true);
    }

    return ans;

}
void solve() {
    int n;
    cin >>n;
    // int arr[n];

    // cout <<func(n, arr, 0) <<endl;

    cout << func1(n , 1, false);

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