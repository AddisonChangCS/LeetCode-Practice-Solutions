#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum=0, cur_sum=0;
        
        for (int i = 0; i < k; i++)
        {
            cur_sum+=nums[i];
        }
        max_sum=cur_sum;

        for (int right_ptr = k; right_ptr < nums.size(); right_ptr++)
        {
            cur_sum=cur_sum-nums[right_ptr-k]+nums[right_ptr];
            max_sum=max(cur_sum,max_sum);
        }
        return static_cast<double>(max_sum) / k;
    }
};