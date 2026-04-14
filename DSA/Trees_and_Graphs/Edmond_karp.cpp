#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n; // number of vertices

// BFS to find augmenting path
int bfs(vector<vector<int>>& capacity,
        vector<vector<int>>& adj,
        int s, int t,
        vector<int>& parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pair<int,int>> q;
    q.push({s, INT_MAX});

    while(!q.empty()){
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(int next : adj[cur]){
            if(parent[next] == -1 && capacity[cur][next] > 0){
                parent[next] = cur;

                int new_flow = min(flow, capacity[cur][next]);

                if(next == t)
                    return new_flow;

                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

// Edmonds-Karp Algorithm
int edmondsKarp(vector<vector<int>>& capacity,
                vector<vector<int>>& adj,
                int s, int t)
{
    int flow = 0;
    vector<int> parent(n);

    int new_flow;

    while(new_flow = bfs(capacity, adj, s, t, parent)){
        flow += new_flow;

        int cur = t;
        while(cur != s){
            int prev = parent[cur];

            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;

            cur = prev;
        }
    }

    return flow;
}

int main(){

    n = 6; // number of nodes

    vector<vector<int>> capacity(n, vector<int>(n, 0));
    vector<vector<int>> adj(n);

    auto addEdge = [&](int u,int v,int cap){
        capacity[u][v] = cap;
        adj[u].push_back(v);
        adj[v].push_back(u); // reverse edge
    };

    // Example graph
    addEdge(0,1,16);
    addEdge(0,2,13);
    addEdge(1,2,10);
    addEdge(2,1,4);
    addEdge(1,3,12);
    addEdge(3,2,9);
    addEdge(2,4,14);
    addEdge(4,3,7);
    addEdge(3,5,20);
    addEdge(4,5,4);

    int source = 0;
    int sink = 5;

    cout << "Maximum Flow = "
        << edmondsKarp(capacity, adj, source, sink);

    return 0;
}
