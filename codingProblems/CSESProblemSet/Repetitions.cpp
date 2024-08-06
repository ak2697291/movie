#include<bits/stdc++.h>

using namespace std;

int main() {

 int max = 0, maxA = 0, maxC = 0, maxG = 0,maxT = 0;
 string s;
 cin >> s;
 for (int i= 0;i <s.length(); i++) {
    if (s[i] == 'A') {
        maxA = maxA +1;
        if (maxA > max) {
            max = maxA;
        }
        maxC = 0;
         maxG = 0;
         maxT = 0;
    }
    if (s[i] == 'C') {
        maxC = maxC +1;
        if (maxC > max) {
            max = maxC;
        }
         maxA = 0;
         maxG = 0;
         maxT = 0;
    }
    if (s[i] == 'G') {
        maxG = maxG +1;
        if (maxG > max) {
            max = maxG;
        }
        maxC = 0;
         maxA = 0;
         maxT = 0;
    }
    if (s[i] == 'T') {
        maxT = maxT +1;
        if (maxT > max) {
            max = maxT;
        }
        maxC = 0;
         maxG = 0;
         maxA = 0;
    }
 }
 cout <<max;
 
}