#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)
    // Space O(1)
    int longestOnes(vector<int>& nums, int k) {
        int left_ptr=0, right_ptr=0;
        int zero_count=0;
        int max_len=0;
        
        for (left_ptr, right_ptr; right_ptr < nums.size(); right_ptr++)
        {
            if (nums[right_ptr]==0) zero_count++;
            while (zero_count>k)
            {
                if (nums[left_ptr]==0) zero_count--;
                left_ptr++;
            }
            if (right_ptr-left_ptr+1>max_len) max_len=right_ptr-left_ptr+1;
        }
        return max_len;
    }
};