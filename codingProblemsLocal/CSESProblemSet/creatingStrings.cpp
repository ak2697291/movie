#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back
void solve() {
   string s;
   cin>>s;
   vector<string> result;
   sort(s.begin(), s.end());
   do {
      result.push_back(s);
   }while(next_permutation(s.begin(), s.end()));

   cout<<result.size()<<endl;
   for(int i=0;i<result.size();i++) {
      cout<<result[i]<<endl;
   }

}
int32_t main() {
// #ifndef ONLINE_JUDGE
// freopen("output.txt", "w", stdout);
// freopen("input.txt", "r", stdin);
// #endif
int t= 1;
while(t--) {
solve();
}
return 0;
}