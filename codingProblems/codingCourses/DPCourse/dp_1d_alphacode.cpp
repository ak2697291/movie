#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back

vector<int> memo;

int comb(string s,int i) {
if (i == s.length()) {

    return 1;
}


int &ans = memo[i];

if (ans != -1) {
    return ans;
}
ans = 0;

if (s[i]>='1' && s[i] <= '9') {

    ans +=  comb(s, i+1);
}


if ((s[i]=='1')&& i+1 < s.length()) {

    ans +=  comb(s, i+2);
}

if ( i+1 < s.length() && (s[i]=='2' && s[i+1] <= '6')) {

    ans +=  comb(s, i+2);
}
return ans;

}
void solve() {
while(true) {
    string s;
    cin >> s;
    if (s == "0"){
        break;
    }
    memo.clear();
    memo.resize(s.size()+1, -1);
    cout<<comb(s, 0)<<endl;

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