#include<bits/stdc++.h>

using namespace std;
int fact(int n) {
    if (n==0)
    return 1;
    return n * fact(n-1);
}
int main() {
 string s;
 cin>>s;
 int n = s.length();
 int arr[26]= {0};
 for(int i = 0;i <n;i++) {
    int temp = s[i] - 97;
    arr[temp] = arr[temp] +1;
 }
 int total = fact(n);
 for (int i=0;i<26;i++) {
    total = total/fact(arr[i]);
 }
 cout << total<<endl;
 

}