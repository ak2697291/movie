#include<bits/stdc++.h>

using namespace std;


int main() {
    long long n;
    cin>>n;


    long long divisor = 5;
    long long result = 0;
    while (n/divisor != 0) {
        result = result + n/divisor;
        divisor = divisor*5;
    }

    cout<<result;
}