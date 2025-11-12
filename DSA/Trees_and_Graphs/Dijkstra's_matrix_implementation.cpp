#include <iostream>
#include <queue>
#include <algorithm>
#define max 10
#define INF 999999
using namespace std;

int main(){
    int matrix[max][max];
    int n, source;
    
    // Input: number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;
    
    // Input: adjacency matrix
    cout << "Enter adjacency matrix (use " << INF << " for no edge):\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    
    // Input: source vertex
    cout << "Enter source vertex (0-indexed): ";
    cin >> source;
    
    // Dijkstra's Algorithm
    int distance[max], visited[max], prev[max];
    
    // Initialize
    for(int i = 0; i < n; i++){
        distance[i] = INF;
        visited[i] = 0;
        prev[i] = -1;
    }
    distance[source] = 0;
    
    // Main loop: repeat n times
    for(int count = 0; count < n; count++){
        // Find unvisited vertex with minimum distance
        int minDist = INF, u = -1;
        for(int i = 0; i < n; i++){
            if(!visited[i] && distance[i] < minDist){
                minDist = distance[i];
                u = i;
            }
        }
        if(u == -1) break; // No reachable vertex left
        
        visited[u] = 1;
        
        // Relax edges from u
        for(int v = 0; v < n; v++){
            if(matrix[u][v] != INF && distance[u] + matrix[u][v] < distance[v]){
                distance[v] = distance[u] + matrix[u][v];
                prev[v] = u;
            }
        }
    }
    
    // Output shortest distances and paths
    cout << "\nShortest distances from vertex " << source << ":\n";
    for(int i = 0; i < n; i++){
        cout << source << " -> " << i << ": ";
        if(distance[i] == INF){
            cout << "INF (unreachable)\n";
        } else {
            cout << distance[i] << " | Path: ";
            // Reconstruct path
            vector<int> path;
            for(int v = i; v != -1; v = prev[v]){
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            for(int j = 0; j < path.size(); j++){
                if(j) cout << " -> ";
                cout << path[j];
            }
            cout << "\n";
        }
    }
    
    return 0;
}
