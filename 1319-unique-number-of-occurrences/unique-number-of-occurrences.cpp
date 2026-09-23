#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(N)
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for(auto const& i : arr)
        {
            map[i]++;
        }
        unordered_set<int> set;
        for (auto const& [key, value]: map)
        {
            set.insert(value);
        }
        return map.size() == set.size();
    }
};