#include <vector>
#include <unordered_map>
using namespace std;

struct VectorHash
{
    size_t operator()(const std::vector<int>& v) const {
        size_t hash = 0;
        for (int num : v) {
            //Boost Hash Combine
            hash ^= std::hash<int>{}(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
class Solution {
public:
    //Time: O(N^2)
    //Space: O(N)
    int equalPairs(vector<vector<int>>& grid) {
        //build row hash set
        unordered_map<vector<int>,int,VectorHash> row_set;
        for (auto const& row : grid)
        {
            row_set[row]++;
        }

        //colunm look up
        int count=0;
        vector<int> colunm(grid.size());
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                colunm[j]=grid[j][i]; 
            }
            auto iter=row_set.find(colunm);
            if (iter!=row_set.end())
            {
                count+=iter->second;
            }
        }
        return count;
    }
};
