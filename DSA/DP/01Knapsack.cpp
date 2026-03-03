#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, W;
    cin >> n >> W;

    vector<int> P(n), weight(n);

    for(int i = 0; i < n; i++)
        cin >> P[i];

    for(int i = 0; i < n; i++)
        cin >> weight[i];

    vector<vector<int>> DP(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++){
        for(int w = 1; w <= W; w++){
            if(weight[i-1] <= w){
                DP[i][w] = max( DP[i-1][w], DP[i-1][w - weight[i-1]] + P[i-1] );
            }
            else{
                DP[i][w] = DP[i-1][w];
            }
        }
    }

    cout << DP[n][W];
}
