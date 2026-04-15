#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int n;
int dist[10][10];
int dp[1024][10]; // 1024 = 2^10, where 10 = number of cities. Change that if # of cities change.

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) return dist[pos][0]; 
    if (dp[mask][pos] != -1) return dp[mask][pos]; 
    
    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city))) {
            ans = min(ans, dist[pos][city] + tsp(mask | (1 << city), city)); 
        }
    }
    
    return dp[mask][pos] = ans; 
    /* 
    "Given the cities I have already visited (Row), and the city I am currently standing in (Column), 
    what is the absolute shortest distance to visit the remaining unvisited cities and return to the start?"
    */
}

int main() {
    n = 4;

    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int shortest_path = tsp(1, 0);

    cout << "The shortest possible route distance is: " << shortest_path << "\n";

    return 0;
}
