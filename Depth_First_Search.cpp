#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<bool> &vis, vector<int> adj[],vector<int> &store) {
    store.push_back(i);
    vis[i]=true;
    for(auto i:adj[i]){
        if(!vis[i]){
            dfs(i,vis,adj,store);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
        vector<int> adj[V+1];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V,false);
        vector<vector<int>> storeDfs;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int> nodes;
                dfs(i,visited,adj,nodes);
                storeDfs.push_back(nodes);
            }
        }
        return storeDfs;
}
int main(){
    int v=5;
    int e=4;
    vector<vector<int>> edges={{0,2},{0,1},{1,2},{3,4}};
    depthFirstSearch(v,e,edges);
}
