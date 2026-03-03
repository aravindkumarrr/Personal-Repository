#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    // Create DP table of size (n+1) x (m+1)
    vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            }
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << DP[n][m];

    return 0;
}
