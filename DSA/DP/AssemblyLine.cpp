#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of stations: ";
    cin >> n;

    vector<vector<int>> a(2, vector<int>(n));     // Processing time
    vector<vector<int>> t(2, vector<int>(n-1));   // Transfer time

    int e1, e2, x1, x2;

    cout << "Enter entry times (e1 e2): ";
    cin >> e1 >> e2;

    cout << "Enter exit times (x1 x2): ";
    cin >> x1 >> x2;

    cout << "Enter processing times for line 1:\n";
    for(int i = 0; i < n; i++)
        cin >> a[0][i];

    cout << "Enter processing times for line 2:\n";
    for(int i = 0; i < n; i++)
        cin >> a[1][i];

    cout << "Enter transfer times from line 1 to 2:\n";
    for(int i = 0; i < n-1; i++)
        cin >> t[0][i];

    cout << "Enter transfer times from line 2 to 1:\n";
    for(int i = 0; i < n-1; i++)
        cin >> t[1][i];

    // DP arrays
    vector<int> f1(n), f2(n);

    // Base case
    f1[0] = e1 + a[0][0];
    f2[0] = e2 + a[1][0];

    // Fill DP table
    for(int i = 1; i < n; i++) {
        f1[i] = min(f1[i-1] + a[0][i],
                    f2[i-1] + t[1][i-1] + a[0][i]);

        f2[i] = min(f2[i-1] + a[1][i],
                    f1[i-1] + t[0][i-1] + a[1][i]);
    }

    // Final answer
    int result = min(f1[n-1] + x1, f2[n-1] + x2);

    cout << "Minimum time required: " << result << endl;

    return 0;
}
