#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    int longestSubarray(vector<int>& nums) {
        int max_len=0;
        int zero_count=0;
        for (int left_ptr = 0, right_ptr=0; right_ptr < nums.size(); right_ptr++)
        {
            if (nums[right_ptr]==0) zero_count++;
            while (zero_count>1)
            {
                if (nums[left_ptr]==0) zero_count--;
                left_ptr++;
            }
            if (right_ptr-left_ptr> max_len) max_len=right_ptr-left_ptr;
        }
        return max_len;
    }
};