#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define pb push_back
#define fi first
#define se second

void TOH(int n, char A, char B, char C) {
	
	if (n==0)
		return;
	TOH(n-1, A, C,B);
	cout<<A << "->"<<C<<endl;
	TOH(n-1,B, A,C );
}

void solve(){
	int n;
	
	cin>>n;

	TOH(n, 'A', 'B', 'C');
}

int32_t main() {
	
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

int t=1;
// cin>>t;
while(t--) {
	solve();
}
}