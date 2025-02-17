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


5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9