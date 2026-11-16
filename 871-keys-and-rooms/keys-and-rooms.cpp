class Solution {
public:
    vector<bool> visited;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited = vector<bool>(rooms.size(), false);
        DFS(0, rooms);
        for(int i=0; i<visited.size(); i++){
            if(!visited[i]) return false;
        }
        return true;
    }
    void DFS(int cur, vector<vector<int>>& graph){
        if(!visited[cur]){
            visited[cur]=true;
            for(int i=0; i<graph[cur].size(); i++){
                DFS(graph[cur][i], graph);
            }
        }
    }
};