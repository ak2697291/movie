#include<bits/stdc++.h>

using namespace std;

// #define int long long int
#define F first
#define S second
#define pb push_back

void print2dArray(int arr[][100], int n) {
		for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
		 cout <<arr[i][j]<<" ";
		}
		cout <<endl;
	}
	cout<<endl;
}

bool checkPlace(int  arr[][100], int n, int i, int j, int k) {
	//check row

	for (int l = 0; l<n; l++) {
		if (k == arr[i][l]) {
			return false;
		}
	}

	// check column

	for (int l = 0;l<n ;l++) {
		if (k == arr[l][j]) {
			return false;
		}
	} 

	//check subgrid
	int starti = i - i%3, startj = j - j%3, endi = starti + 2, endj = startj + 2;
	for(int a = starti; a <= endi; a ++) {
		for (int b = startj; b <= endj; b ++) {
			if (k == arr[a][b]) {
				return false;
			}
		}
	}


return true;

}

bool func(int n, int arr[][100], int i, int j) {
	if (i == n){
		print2dArray(arr, n);
		return true;
	}
	if (j == n) {
		return func(n, arr, i+1, 0);
	}
	if (arr[i][j] !=0) {
		return func(n, arr, i, j+1);
	}

	for(int k = 1;k<= n; k++) {
		if (checkPlace(arr, n, i, j ,k)) {
			arr[i][j] = k;
			bool success = func(n, arr,i,j+1);
			if (success) {
				return true;
			}
		}
	}
	arr[i][j] = 0;

	return false;
}
void solve() {
	int n;
	cin >> n;
	int arr[100][100];
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			int temp;
			cin >> temp;
			arr[i][j]  = temp; 
		}
	}
	if (!func(n, arr, 0, 0)) {
		cout << "No Solution"<<endl;
	}

	
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