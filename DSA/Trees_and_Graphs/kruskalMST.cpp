#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};
bool compareEdges(Edge a, Edge b){
    return a.weight<b.weight;
}
int find(vector<int>&parent, int i){
    if(parent[i]==i) return i;
    return parent[i] = find(parent,parent[i]);
}

void unionSets(vector<int>&parent, vector<int>& rank, int x, int y){
    int xroot = find(parent, x);
    int yroot = find(parent,y);
    if(rank[xroot]<rank[yroot]){
        parent[xroot]=yroot;
    }
    else if (rank[xroot]>rank[yroot]){
        parent[yroot] = xroot;
    }
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskallMST(vector<Edge>&edges, int V){
    sort(edges.begin(),edges.end(),compareEdges);
    vector<int> parent(V), rank(V,0);
    for(int i=0;i<V;i++) parent[i] = i;

    int mincost=0;
    int edgesused=0;
    
    for(auto& e:edges){
        int x = find(parent,e.u);
        int y = find(parent, e.v);
        if(x!=y){
            unionSets(parent, rank, x, y);
            mincost+= e.weight;
            cout<<e.u<<" "<<e.v<<" "<<" "<<e.weight<<endl; // Required for printing edgewise output
            edgesused++;
            if(edgesused==V-1) break;
        }
    }
    cout<<"Total Cost = "<<mincost<<endl;

}

int main(){
    int V;
    vector<Edge> edgelist;
    cin >> V;
    // Edge temp;
    // while(cin >> temp.u >> temp.v >> temp.weight){
    //     edgelist.push_back(temp);
    // }
    
    kruskallMST(edgelist,V);
}
