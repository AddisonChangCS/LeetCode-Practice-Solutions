class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    //Time: O(N)
    //Space: O(N)
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> result;
        //build adj list: <key:value>=<eq1:edge, value>
        for(int i=0; i<values.size(); i++){
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        for(int i=0; i<queries.size(); i++){
            unordered_set<string> visited;
            visited.insert(queries[i][0]);
            result.push_back(DFS(queries[i][0], queries[i][1], visited));
        }
        return result;
    }
    double DFS(string cur,  string target, unordered_set<string> &visited){
        double count=-1.0;
        if (!adj.contains(cur) || !adj.contains(target)) return -1.0;
        if(cur==target) return 1.0;
        for(int i=0; i<adj[cur].size(); i++){
            if (!visited.contains(adj[cur][i].first)) {
                visited.insert(adj[cur][i].first);
                count=DFS(adj[cur][i].first, target, visited);
                if(count!=-1.0) return count*adj[cur][i].second;
            }
        }
        return count;
    }
};