#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    void moveZeroes(vector<int>& nums) {
        int fast_ptr=0,slow_ptr=0;
        for (; fast_ptr < nums.size(); fast_ptr++)
        {
            if (nums[fast_ptr]!=0)
            {
                nums[slow_ptr++]=nums[fast_ptr];
            }
            
        }
        for (; slow_ptr < nums.size(); slow_ptr++)
        {
            nums[slow_ptr]=0;
        }
    }
};