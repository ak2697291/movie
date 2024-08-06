#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;
  if (n ==1) {
    cout << n;
    return 0;
  }
   if (n <=3) {
    cout << "NO SOLUTION";
    return 0;
   }
   if (n==4) {
    cout <<"2 4 1 3";
    return 0;
   }

   int firstSeries = n, secondSeries = n-1;
   bool flagOne = true, flagTwo = true;
   long long result[1000000];
   result[0] = firstSeries;
   for (int i=1;i<n;i++) {
    if (flagOne) {
        firstSeries = firstSeries - 2;
        if (firstSeries >=1 && firstSeries <= n) {
            result[i] = firstSeries;
        } else {
            flagOne = false;
        }
    } 
    if (!flagOne && flagTwo) {
        if (secondSeries >=1 && secondSeries <=n) {
            result[i] = secondSeries;
            secondSeries = secondSeries - 2;
        } else {
            flagTwo = false;
        }
    }
    if (result[i] - result[i - 1] == 1 || result[i] - result[i - 1] == -1) {
        cout <<"NO SOLUTION";
        return 0;
    }
    if (!flagOne && !flagTwo) {
        break;
    }
   }

   for (int i=0; i<n ;i++) {
    cout << result[i] <<" ";
   }



}