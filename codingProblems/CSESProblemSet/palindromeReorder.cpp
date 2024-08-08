#include<bits/stdc++.h>

using namespace std;

int main() {
 string s;
 cin >>s;
 int arr[26] = {0};
 for (int i=0; i< s.length();i++) {
    int t = s[i] - 65;
    arr[t] = arr[t] + 1;
 }   
int count = 0;
int single = 0;
 for(int i=0;i < 26; i++) {
    if (arr[i]%2 ==1) {
        single = i;
        count++;
        if (count>1) {
            cout << "NO SOLUTION";
            return 0;
        }
    }
 }
 char a = 65 + single;
 string result(arr[single], a);

if (arr[single] % 2 ==0) {
    result = "";
}
 for(int i=0;i<26;i++) {
    if(arr[i] >0 && arr[i]%2 !=1) {
        string first(arr[i]/2, i+65);

        result = first + result + first;
    }

 }
 cout<<result;


}