#include<bits/stdc++.h>

using namespace std;

// #define int long long int
#define F first
#define S second
#define pb push_back
#define N 100000

vector<int> gr[N];
int n, m;
int visited[N];

bool hamiltonianpath = false;

void hpath(int visitCount, int curr) {
	if (visitCount == n) {
		hamiltonianpath = true;
		return;
	}
	visited[curr] = 1;

	for (auto x : gr[curr]) {
		if (!visited[x]) {
			hpath(visitCount+1, x);
		}
	}
	// backtracking
	visited[curr] = 0;

	return;
}

void solve() {
	cin>>n>>m;

	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	// for(const auto &g : gr) {
	// 	for (const auto &element : g) {
	// 		cout<<element<<" ";
	// 	}
	// 	cout<<endl;
	// }

	for (int i=0; i<n; i++) {

		hpath(1, i);

	}
	
	if (hamiltonianpath) {
		cout <<"path exists"<<endl;
	} else {
	cout<<"path doesn't exists"<<endl;
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