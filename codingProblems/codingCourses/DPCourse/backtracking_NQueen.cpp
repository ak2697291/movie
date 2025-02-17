#include<bits/stdc++.h>

using namespace std;

// #define int long long int
#define pb push_back
#define fi first
#define se second
// int arr[10000][10000]={0};
bool isEligible(int n,int arr[][20], int i, int j) {
	int k = i, l = j;
	while(k > 0 && l >0) {
		k--;
		l--;
		if (arr[k][l] == 1) {
			return false;
		}
	}
	k = i;
	l = j;
	while(k>0 && l<n) {
		k--;
		l++;
		if (arr[k][l] == 1) {
			return false;
		}
	}
	k = i;
	l = j;
	while(k>0) {
		k--;
		if(arr[k][l] == 1) {
			return false;
		}
	}

	return true;
}

void printBoard(int n, int arr[][20]) {

	for(int i=0;i<n;i++) {
		for(int j =0; j<n;j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


bool func(int n,int arr[][20], int i) {

	if (i == n) {
		printBoard(n, arr);
		return true;
	}


for(int j = 0;j<n;j++) {
if (isEligible(n,arr, i, j)) {
		arr[i][j] = 1;
		bool success = func(n,arr, i+1);
		if (success) {
			return true;
		} 
		arr[i][j] =0;
	}
}
	

return false;

}

void solve(){
	int n;
	cin>>n;
	int arr[20][20] = {0};
	if (func(n,arr,0)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO";
	}
	// cout<<func(n,0,0);
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