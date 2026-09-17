#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    int largestAltitude(vector<int>& gain) {
        int max_height=0;
        for (int i = 0, cur_height=0; i < gain.size(); i++)
        {
            cur_height+=gain[i];
            if(cur_height>max_height) max_height=cur_height;
        }
        return max_height;
    }
};