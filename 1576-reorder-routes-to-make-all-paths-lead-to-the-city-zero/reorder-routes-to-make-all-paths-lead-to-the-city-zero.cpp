class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<bool> visited;
    //Time: O(N)
    //Space: O(N)
    int minReorder(int n, vector<vector<int>>& connections) {
        adj=vector<vector<pair<int, int>>>(n);
        visited=vector<bool>(n, false);
        for(const auto & edge:connections){
            adj[edge[0]].push_back({edge[1], 1});
            adj[edge[1]].push_back({edge[0], 0});
        }    
        visited[0]=true;
        return DFS(0);
    }
    int DFS(int cur){
        int count=0;
        for(int i=0; i<adj[cur].size(); i++){
            if(!visited[adj[cur][i].first]){
                visited[adj[cur][i].first]=true;
                count+=adj[cur][i].second;
                count+=DFS(adj[cur][i].first);
            }
        }
        return count;
    }
};