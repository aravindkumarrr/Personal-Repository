#include <iostream>
#include <vector>
#include <queue>

using namespace std;


#define INF 9999


typedef pair<pair<int, int>, int> Edge;

void primMST(int n, vector<pair<int, int>> adj[]) {
    
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> key(n, INF);     
    vector<int> parent(n, -1);   
    vector<bool> inMST(n, false);

    
    pq.push({0, 0});
    key[0] = 0;

    int total_cost = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;

        
        for (auto x : adj[u]) {	 	  	 	    	   	    	   	  	  	    	 	
            int v = x.first;
            int weight = x.second;

            
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    
    
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] + 1 << " " << i + 1 << endl;
            total_cost += key[i];
        }
    }
    cout<<total_cost;
}

int main() {
    int n;
    
    cin >> n;

    
    
    vector<pair<int, int>> adj[n];

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int weight;
            cin >> weight;
            
            if (weight != INF && i != j) {	 	  	 	    	   	    	   	  	  	    	 	
                adj[i].push_back({j, weight});
            }
        }
    }

    primMST(n, adj);

    return 0;
}
