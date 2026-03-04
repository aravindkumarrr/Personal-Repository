#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, dist[10][10], dp[1024][10];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) return dist[pos][0];  // all cities visited, return to start
    if (dp[mask][pos] != -1) return dp[mask][pos];   // already computed, return cached result
    
    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
        if (!(mask & (1 << city)))                   // if city not yet visited
            ans = min(ans, dist[pos][city] + tsp(mask | (1 << city), city));  // visit it
    
    return dp[mask][pos] = ans;  // cache and return best distance
}
