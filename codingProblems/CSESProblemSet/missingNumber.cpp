#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >>n;
    long long sum = n * (n +1) /2;


    for (int i = 1; i < n; i ++) {
    int k;
    cin>>k;
    sum = sum - k;

    }
   cout << sum;


}