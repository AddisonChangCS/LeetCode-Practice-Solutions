#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        int prefix=1, suffix=1;
        for (int pre_ptr = 0; pre_ptr < nums.size(); pre_ptr++)
        {
            result[pre_ptr]=prefix;
            prefix*=nums[pre_ptr];
        }
        for (int suf_ptr = nums.size()-1; suf_ptr >= 0; suf_ptr--)
        {
            result[suf_ptr]*=suffix;
            suffix*=nums[suf_ptr];
        }
        return result;
    }
};