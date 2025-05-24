#include<bits/stdc++.h>
using namespace std;
#define int long long unsigned int
#define F first
#define S second
#define pb push_back
void solve() {
    int n;
    cin>>n;
    int digits = 1;
    int count = 9;
    int start = 1;

    // Find the block (1-digit, 2-digit, etc)
    while (n > digits * count) {
        n -= digits * count;
        digits++;
        count *= 10;
        start *= 10;
    }

    // Find the actual number
    start += (n - 1) / digits;
    string s = to_string(start);
    cout << s[(n - 1) % digits] << endl;


}
int32_t main() {

int t;
cin>>t;
while(t--) {
solve();
}
return 0;
}
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25..
