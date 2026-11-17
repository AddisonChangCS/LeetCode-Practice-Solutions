class Solution {
public:
    vector<vector<bool>> visited;
    bool isValid(int row, int col, int m, int n, vector<vector<int>>& grid){
        return (row>=0 && row<m) && (col>=0 && col<n) && grid[row][col]==1 && !visited[row][col];  
    }
    //Time: O(N)
    //Space: O(N)
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        visited=vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                    visited[i][j]=true;
                }
            }
        }
        int min=-1;
        for(; !q.empty(); min++){
            int size=q.size();
            for(int i=0; i<size; i++){
                auto [row, col]=q.front();
                q.pop();
                if(isValid(row+1, col, grid.size(), grid[0].size(), grid)){
                    q.push({row+1, col});
                    visited[row+1][col]=true;
                    grid[row+1][col]=2;
                }
                if(isValid(row-1, col, grid.size(), grid[0].size(), grid)){
                    q.push({row-1, col});
                    visited[row-1][col]=true;
                    grid[row-1][col]=2;
                }
                if(isValid(row, col+1, grid.size(), grid[0].size(), grid)){
                    q.push({row, col+1});
                    visited[row][col+1]=true;
                    grid[row][col+1]=2;
                }
                if(isValid(row, col-1, grid.size(), grid[0].size(), grid)){
                    q.push({row, col-1});
                    visited[row][col-1]=true;
                    grid[row][col-1]=2;
                }
            }
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return min<0?0:min;
    }
};