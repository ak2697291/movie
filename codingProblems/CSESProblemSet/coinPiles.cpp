#include<bits/stdc++.h>

using namespace std;
string checkCases(long long a, long long b) {
    if ((a==1&&(b==1)) || (a==2 && (b==2 ||b==3)) || (b==1&&(a==1)) || (b==2 && (a==2 ||a==3))){
        return "NO";
    }
    return "YES";
}
int main() {
 int t;
 cin>>t;
 for (int k = 0;k<t;k++) {
    long long a, b;
    cin>>a>>b;
    if ((a+b)%3!=0 || (a > 2*b) || (b >2*a)) {
        cout << "NO" <<endl;
        continue;
    }
    if ("YES"==checkCases(a,b)) {
        cout <<checkCases(a%3, b%3)<<endl;
        continue;
    }
    cout << "NO"<<endl;

 }   
}