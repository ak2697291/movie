#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

void func(int n, char *in, int j,int k, char *out) {
	
if (in[j] == '\0') {
	out[k] = '\0';
	cout<<out<<endl;
	return;
}

	out[k] = in[j];
	func(n, in, j+1,k+1, out);
	func(n, in, j+1, k, out);
}


void solve() {
	int n;

cin>>n;
	char in[n];

	for (int i=0; i<n; i++) {
		char temp;
		cin>>temp;
		in[i] = temp;
	}
	char out[n+1];

	func(n, in, 0,0,out);
}

int32_t main() {

#ifndef ONLINE_JUDGE	
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
#endif

	int t= 1;
	while(t--) {

		solve();
	}

return 0;

}