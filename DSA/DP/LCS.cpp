#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string X, Y;
    cout << "Enter string X: ";
    cin >> X;
    cout << "Enter string Y: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    vector<vector<int>> LCS(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            } else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    string lcs_str = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str += X[i - 1];
            i--;
            j--;
        } else if (LCS[i - 1][j] >= LCS[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs_str.begin(), lcs_str.end());

    cout << "LCS Length: " << LCS[m][n] << endl;
    cout << "LCS String: " << lcs_str << endl;

    return 0;
}
