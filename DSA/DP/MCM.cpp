#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;

    cin>>n;

    vector<int> p(n+1,0);
    for(int i=0;i<n+1;i++){
        int temp;
        cin>>temp;
        p[i] = temp;
    }

    vector<vector<int>>DP(n, vector<int>(n,0));

    for(int chlength = 2; chlength<=n; chlength++){
        for(int i=0; i<=n-chlength;i++){
            int j = i+chlength - 1;
            DP[i][j] = INT_MAX;

            for(int k=i;k<j;k++){
                DP[i][j] = min(DP[i][j], DP[i][k]+DP[k+1][j]+ p[i]*p[k+1]*p[j+1]);
            }
        }
    }

    cout<<DP[0][n-1];
}
