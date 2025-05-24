#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back
int mini = INT_MAX;
int maxSum = 0;
void findMinDiff(vector<int>&nums, int sum, int half, int i) {
if (i >= nums.size()) return;

if (sum + nums[i] <= half) {

    mini = min (mini, abs(half - sum + nums[i]));
    maxSum  = max(maxSum, nums[i] + sum);

    findMinDiff(nums, sum + nums[i], half, i+1);
    findMinDiff(nums, sum, half, i+1);
}else {
    findMinDiff(nums, sum, half, i+1);
}


}
void solve() {
    int n;
    cin>>n;
    vector<int> nums;



    int sum = 0;
    for(int i=0;i<n;i++) {
        int t;
        cin >> t;
        nums.push_back(t);
        sum += t;

    }

    int half;
    if (sum%2)
    half = sum/2 + 1;
    else {
        half = sum/2;
    }
    findMinDiff(nums, 0, half, 0);


    cout<<abs(sum - 2 * maxSum)<<endl;




 
    
}
int32_t main() {
#ifndef ONLINE_JUDGE
// freopen('output.txt','w',stdout);
// freopen('input.txt','r',stdin);
#endif
int t= 1;
while(t--) {
solve();
}
return 0;
}