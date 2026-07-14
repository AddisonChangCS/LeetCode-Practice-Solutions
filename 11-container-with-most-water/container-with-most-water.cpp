#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    int maxArea(vector<int>& height) {
        int max_area=0;
        for (int left_ptr = 0, right_ptr = height.size()-1; left_ptr < right_ptr;)
        {
            int cur_area=min(height[right_ptr],height[left_ptr]) * (right_ptr-left_ptr);
            max_area=max(max_area,cur_area);
            
            if (height[left_ptr]>height[right_ptr])
            {
                right_ptr--;
            }
            else
            {
                left_ptr++;
            }
        }
        return max_area;
    }
};