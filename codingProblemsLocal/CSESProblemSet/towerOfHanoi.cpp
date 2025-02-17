#include <bits/stdc++.h>

using namespace std;
vector<vector<char> > result;

void TOH(int n, char a, char c, char b) {
    if (n == 0)
        return;
    TOH(n-1, a, b, c);

    // Create a temporary vector and push it to result
    vector<char> move;
    move.push_back(a);
    move.push_back(c);
    result.push_back(move);

    TOH(n-1, b, c, a);
}

int main() {
    int n;
    cin >> n;

    TOH(n, '1', '3', '2');
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
}
