#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

void printArray(char arr[], int n) {
	for(int i=0;i<2*n;i++) {
		cout<<arr[i];
	}
	cout<<endl;
}
void func(int n, char arr[], int i, int j, int k) {
	if (j >= n) {
		printArray(arr, n);
		return;
	}

	if (i<n) {
		arr[k] = '(';
		func(n, arr, i+1, j, k+1);
	}
	if (i>j) {
		arr[k] = ')';
		func(n, arr, i, j+1, k+1);
	}
}

void solve() {
	
	int n;
	cin >>n;
	char arr[2*n];

	func(n, arr, 0, 0, 0);
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