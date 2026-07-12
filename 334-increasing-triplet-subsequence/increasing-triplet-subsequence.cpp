#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    bool increasingTriplet(vector<int>& nums) {
        int first_min=__INT32_MAX__, second_min=__INT32_MAX__;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]>second_min)
            {
                return true;
            }
            else if (nums[i]<first_min)
            {
                first_min=nums[i];
            }
            else if (nums[i]<second_min && nums[i]>first_min)
            {
                second_min=nums[i];   
            }
            
        }
        return false;
    }
};