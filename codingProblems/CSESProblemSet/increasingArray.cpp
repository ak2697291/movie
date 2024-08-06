#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >>n;
    long long arr[1000000];
    for (int i = 0;i<n;i++) {
        long long k;
        cin >>k;
        arr[i] = k;
    }
    long long count = 0, prev = arr[0];
    for (int i=1;i<n;i++) {
        long long curr = arr[i];

        if (curr < prev) {
            count = count + prev - curr;
            
        } else {
            prev = curr;
        }
    }

    cout <<count;

}