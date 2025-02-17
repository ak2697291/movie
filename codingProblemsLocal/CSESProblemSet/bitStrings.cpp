#include<bits/stdc++.h>

using namespace std;

int main() {

 long long n;
 cin>>n;
 long long modulo = 1000000007;
 long long result = 2;
 for (int i = 2; i<=n; i++) {
    result = result * 2;
result  = result%modulo;
 }
 cout << result%modulo ;

}