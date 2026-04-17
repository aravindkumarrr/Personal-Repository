#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    int n, W;
    cin>>n>>W;
    vector<int> p(n), weight(n);
    
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    vector<vector<int>>DP(n+1, vector<int>(W+1,0));

    for(int i=1;i<=n;i++){
        // Burglar in a house with a backpack of limit W. He's going through the n items one by one.
        for(int w=1;w<=W;w++){
            // If it fits, ask if bag is worth more if I dump out and make space for it, or leaving it behind
            if(weight[i-1]<=w){
                DP[i][w] = max(DP[i-1][w], DP[i-1][w-weight[i-1]]+p[i-1]);
                // w-weight[i-1] is basically how much weight free in the backpack if (i-1)th item was discarded
            }
            // Standing in front of item i, if it's too heavy ignore
            else{
                DP[i][w] = DP[i-1][w];
            }
        }
    }
}
