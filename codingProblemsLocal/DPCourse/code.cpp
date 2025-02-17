#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back


int func(int n) {
if (n == 0) {
	return 1;
}

 if (n==1) {
 	return 1;
 }
 if (n == 2) {
 	return 2;
 }


	
	return func(n-1)+ (n-1) * func(n-2);


}
void solve() {
	int n,a;
	
	cin>>n;
	// int a[n];
	// for (int i=0;i<n;i++) {
	// 	int temp;
	// 	cin>>temp;
	// 	a[i] = temp;
	// }
	cout <<func(n);
}


int32_t main() {

#ifndef ONLINE_JUDGE	
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
#endif

int t=1;

// cin>>t;
while(t--) solve();

return 0;

}