class Solution {
private: 
    bool valid_check(int row, int col, int row_size, int col_size, vector<vector<char>>& maze){
        return  (row>=0 && row<row_size) && (col>=0 && col<col_size) && maze[row][col]!='+' && !visited[row][col];
    }
public:
    // row, colunm
    vector<vector<bool>> visited;
    //Time: O(N)
    //Space: O(N)
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        visited = vector<vector<bool>>(maze.size(),vector<bool>(maze[0].size(), false));
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        for(int min=0; !q.empty(); min++){
            int size=q.size();
            for(int i=0; i<size; i++){
                auto [row, col]=q.front();
                q.pop();
                if((row==0 || row==maze.size()-1 || col==0 || col==maze[0].size()-1) && min>0) return min;
                if(valid_check(row+1, col, maze.size(), maze[0].size(), maze)){
                    q.push({row+1, col});
                    visited[row+1][col]=true;
                }
                if(valid_check(row-1, col, maze.size(), maze[0].size(), maze)){
                    q.push({row-1, col});
                    visited[row-1][col]=true;
                }
                if(valid_check(row, col+1, maze.size(), maze[0].size(), maze)){
                    q.push({row, col+1});
                    visited[row][col+1]=true;
                }
                if(valid_check(row, col-1, maze.size(), maze[0].size(), maze)){
                    q.push({row, col-1});
                    visited[row][col-1]=true;
                }
            }
        }
        return -1;
    }
};