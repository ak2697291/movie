#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin>>n;
    string bitString(n, '0');

    unordered_map<string, int> map;
    string prev = bitString;

    map[bitString] = 1;

    cout<<bitString<<endl;
    for(int i=n-1;i>=0;i--){
        string currentString = prev;

        if (prev[i] == '0') {
            currentString[i] = '1';
        }else {
            currentString[i] = '0';
        }

        if (map.find(currentString) == map.end())  {
            map[currentString] =1;


            cout<<currentString<<endl;
            i=n;
            prev = currentString;
        } 
    }


}