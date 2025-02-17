#include<bits/stdc++.h>
#include<math.h>

using namespace std;

long long getDiagonal(long long n) {
if (n==0)
return 1;

return  n *(n-1) + getDiagonal(0);
}

int main() {
    int t;
    cin >>t;
    for (int i = 0;i<t;i++) {
        long long y ,x;
        cin>>y>>x;
        long long maxi = max(y ,x);


        long long diag = getDiagonal(maxi);

        if (maxi%2 == 0) {
        cout << diag + (y - x) <<endl;
        }else {
        cout << diag + (x - y) <<endl;
        }
    }
}