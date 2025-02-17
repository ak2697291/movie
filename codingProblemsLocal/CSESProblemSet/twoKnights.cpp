#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >>n;
    for (int i=1;i <= n;i++) {
        long long attack = 4 * (i-1)*(i-2);
        long long place = (long long)(i*i)*(i*i - 1)/2;
        long long result = place - attack;
        cout<<result<<endl;
    } 
    
}